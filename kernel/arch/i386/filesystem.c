#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>

#include <kernel/filesystem.h>


static struct inode filesystem_inodes[FILESYSTEM_ELEMENTS_MAX_NB] = {0};
static uint16_t filesystem_inodes_pos = 1;

static uint16_t filesystem_current_dir_inode;

static uint8_t memory[1048576];
static uint32_t memory_pos = 0;

void p162(uint16_t n) {
	uint8_t a = n / 256;
	uint8_t b = n % 256;
	printf("%x", a);
	printf("%x", b);
}


void* malloc(size_t sz){
	printf("malloc\n");
	uint8_t* a = memory + memory_pos;
	memory_pos += sz;
	return a;
}

void filesystem_init(void) {
	struct inode temp_inode;
	for (uint16_t i = 0; i < FILESYSTEM_ELEMENTS_MAX_NB; ++i)
	{
		temp_inode = filesystem_inodes[i];
		temp_inode.i_filename = "\0";
		temp_inode.i_addr_a = NULL;
		temp_inode.i_addr_b = NULL;
		filesystem_inodes[i] = temp_inode;
	}
	temp_inode = filesystem_inodes[0];
	temp_inode.i_is_a_dir = true;
	filesystem_inodes[0] = temp_inode;

	uint16_t a = filesystem_new_file("root", true);

	// filesystem_write_file_byte(a, 42, true, 0);
	// filesystem_write_file_byte(a, 42, true, 0);
	// filesystem_write_file_byte(a, 42, true, 0);
	// filesystem_write_file_byte(a, 42, true, 0);

	filesystem_current_dir_inode = a;
	// filesystem_write_file_byte(a, 2, true, 0);
	p162(filesystem_current_dir_inode);
	printf("\n");
	p162(filesystem_inodes_pos);
};

void filesystem_dir_add_element(uint16_t iid, uint16_t filename_iid) {
	struct inode dir = filesystem_inodes[iid];

	if (iid == dir.i_id && dir.i_is_a_dir) {
		dir.i_nb_elements += 1;
		filesystem_inodes[iid] = dir;
		filesystem_open_file(iid);
		uint8_t byte1 = filename_iid / 256;
		uint8_t byte2 = filename_iid % 256;
		filesystem_write_file_byte(iid, byte1, true, 0);
		filesystem_write_file_byte(iid, byte2, true, 0);
		uint8_t c1 = filesystem_read_file_byte(iid, 0);
		uint8_t c2 = filesystem_read_file_byte(iid, 1);
		
		filesystem_read_file(iid);
		printf("//");p162(c1 * 256 + c2);printf("//");
		filesystem_close_file(iid);
		// ?
	} else {
		printf("fs error\n");
	}
}
void* filesystem_dir_read_elements(uint16_t iid) {
	struct inode dir = filesystem_inodes[iid];
	
	if (iid == dir.i_id && dir.i_is_a_dir) {
		// malloc
		uint16_t* result = malloc(sizeof(uint16_t) * (dir.i_nb_elements + 1));
		uint8_t byte1 = 0;
		uint8_t byte2 = 0;
		uint16_t temp_id = 0;
		result[0] = dir.i_nb_elements;
		filesystem_open_file(iid);
		for (int i = 0; i < dir.i_nb_elements; ++i)
		{
			byte1 = filesystem_read_file_byte(iid, 2*i);
			byte2 = filesystem_read_file_byte(iid, 2*i+1);
			temp_id = 256 * byte1 + byte2;
			result[1+i] = temp_id;
		}
		filesystem_close_file(iid);
		return result;
	} else {
		return NULL;
	}
}
void filesystem_dir_remove_element(uint16_t iid, uint16_t filename_iid) {
	struct inode dir = filesystem_inodes[iid];

	if (iid == dir.i_id && dir.i_is_a_dir) {
		uint16_t* old_elements = filesystem_dir_read_elements(iid);
		filesystem_clear_file(iid);
		for (int i = 0; i < dir.i_nb_elements; ++i)
		{
			if (old_elements[i+1] != filename_iid) {
				filesystem_dir_add_element(iid, old_elements[i+1]);
			}
		}
		// ?
		filesystem_inodes[iid] = dir;
	}
}

char* filesystem_find_fn_from_id(uint16_t iid) {
	struct inode dir = filesystem_inodes[iid];

	if (iid == dir.i_id) {
		return dir.i_filename;
	} else {
		return NULL;
	}
}
uint16_t filesystem_find_id_from_fn(char* filename) {
	// struct inode dir = filesystem_inodes[filesystem_current_dir_inode];

	// uint16_t* dir_elements = filesystem_dir_read_elements(filesystem_current_dir_inode);
	// struct inode temp_inode;
	// for (int i = 0; i < dir.i_nb_elements; ++i)
	// {
	// 	temp_inode = filesystem_inodes[dir_elements[i+1]];
	// 	if (! strcmp(filename, temp_inode.i_filename)) {
	// 		return temp_inode.i_id;
	// 	}
	// }
	struct inode temp_inode;
	for (uint16_t i = 0; i < FILESYSTEM_ELEMENTS_MAX_NB; ++i)
	{
		temp_inode = filesystem_inodes[i];
		if (! strcmp(filename, temp_inode.i_filename) && temp_inode.i_parent_id == filesystem_get_cwd()) {
			return i;
		}
	}



	return 0;
}

void fs_correct_fn(uint16_t iid, char* fn) {
	struct inode file = filesystem_inodes[iid];
	file.i_filename = fn;
	filesystem_inodes[iid] = file;
}

uint16_t filesystem_new_file(char* filename, bool is_a_dir) {
	uint16_t iid = filesystem_inodes_pos;

	struct inode new_inode = {
		.i_id = iid,
		.i_filename = filename,
		.i_parent_id = filesystem_current_dir_inode,
		.i_is_a_dir = is_a_dir,
		.i_nb_elements = 0,
		.i_size = 0,
		.i_addr_a = NULL,
		.i_addr_b = NULL
	};
	filesystem_inodes[iid] = new_inode;
	filesystem_dir_add_element(filesystem_current_dir_inode, iid);

	filesystem_inodes_pos += 1;
	// p162(filesystem_inodes_pos);

	return iid;
}

uint16_t filesystem_delete_file(uint16_t iid) {
	// free addr
	struct inode temp_inode = {
		.i_id = 0,
		.i_filename = "\0",
		.i_parent_id = 0,
		.i_is_a_dir = false,
		.i_nb_elements = 0,
		.i_size = 0,
		.i_addr_a = NULL,
		.i_addr_b = NULL
	};
	filesystem_inodes[iid] = temp_inode;
	return iid;
}

void filesystem_clear_file(uint16_t iid) {
	struct inode file = filesystem_inodes[iid];

	file.i_addr_a = NULL;
	file.i_addr_b = NULL;
	file.i_size = 0;

	filesystem_inodes[iid] = file;
}

void filesystem_clear_dir(uint16_t iid) {
	struct inode file = filesystem_inodes[iid];

	if (file.i_nb_elements == 0) {
		file.i_addr_a = NULL;
		file.i_addr_b = NULL;
		file.i_size = 0;
		filesystem_inodes[iid] = file;
	}
}

uint16_t filesystem_open_file(uint16_t iid) {
	return iid;
}
uint16_t filesystem_close_file(uint16_t iid) {
	return iid;
}

void filesystem_write_file_byte(uint16_t iid, uint8_t data, bool eof, uint32_t offset) {
	struct inode file = filesystem_inodes[iid];

	if (eof) {
		if (file.i_size == file.i_addr_b - file.i_addr_a) {
			uint8_t* new_addr_a = malloc(sizeof(uint8_t) * 2 * file.i_size);
			for (int i = 0; i < file.i_size; ++i) {
				new_addr_a[i] = file.i_addr_a[i];
			}
			// free
			file.i_addr_a = new_addr_a;
			file.i_addr_b = new_addr_a + 2 * file.i_size + 1;
		}

		file.i_addr_a[file.i_size] = data;
		printf("</%x\\>\n", file.i_addr_a[file.i_size]);
		file.i_size += 1;
		filesystem_inodes[iid] = file;

		struct inode temp_file = filesystem_inodes[iid];

		printf("</%x\\>\n", temp_file.i_addr_a[temp_file.i_size]);
	} else {
		while (file.i_addr_a + offset > file.i_addr_b) {
			uint8_t* new_addr_a = malloc(sizeof(uint8_t) * 2 * file.i_size);
			for (int i = 0; i < file.i_size; ++i) {
				new_addr_a[i] = file.i_addr_a[i];
			}
			// free
			file.i_addr_a = new_addr_a;
			file.i_addr_b = new_addr_a + 2 * file.i_size + 1;
		}

		file.i_addr_a[offset] = data;
		file.i_size += 1;
	}

	filesystem_inodes[iid] = file;
}

uint8_t filesystem_read_file_byte(uint16_t iid, uint32_t offset) {
	struct inode file = filesystem_inodes[iid];

	uint8_t data;
	if (file.i_addr_a + offset < file.i_addr_b) {
		data = file.i_addr_a[offset];
		printf("<<%x>>", data);
		return data;
	} else {
		return 42;
	}
}




void filesystem_change_dir(uint16_t iid) {
	struct inode file = filesystem_inodes[iid];

	if (iid == file.i_id && file.i_is_a_dir) {
		filesystem_current_dir_inode = iid;
	} else {
		printf("error cd with a dir\n");
	}
}

uint16_t filesystem_get_cwd(void) {
	return filesystem_current_dir_inode;
}

void filesystem_read_file(uint16_t iid) {
	struct inode file = filesystem_inodes[iid];

	for (uint32_t i = 0; i < file.i_size; ++i)
	{
		printf("%x", i);
		printf("%x ", filesystem_read_file_byte(iid, i));
	}
}

void fs_debug(void) {
	struct inode temp_inode;
	p162(filesystem_current_dir_inode); printf("\n");
	for (int i = 0; i < 5; ++i)
	{
		temp_inode = filesystem_inodes[i];
		printf("%x : ", temp_inode.i_id);
		printf("%s ; ", temp_inode.i_filename);
		printf("%x | ", temp_inode.i_parent_id);
		printf("%x \\ ", (unsigned char) temp_inode.i_size);
		filesystem_read_file(temp_inode.i_id);
		printf("\n");
	}
}


void fs_debug_malloc(void) {
	for (unsigned int i = 0; i < 15; ++i)
	{
		printf("\n%x : %c", memory[i], memory[i]);
	}
}
