#define FUSE_USE_VERSION 26

#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <fuse.h>
#include <stdint.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

#define BLOCK_SIZE 512
#define NUM_OF_INODES 15
#define FS_SIZE_MIN 4096
#define INODE_SIZE 256
#define INODE_NUM_DIRECT_BLOCKS 10
#define FREE_BLOCK_LIST_SIZE 20
#define FREE_INODE_LIST_SIZE 20
#define FILE_NAME_LEN_MAX 32

int fs_desc;
typedef uint32_t type;

struct superblock{
    type size_fs;

    type num_free_blocks;
    type list_free_blocks[FREE_BLOCK_LIST_SIZE];
    type index_next_free_block;

    type num_free_inodes;
    type list_free_inodes[FREE_INODE_LIST_SIZE];
    type index_next_free_inode;

    bool is_locked;
};

struct inode{
    type inode_num;
    type file_size;

    time inode_last_accessed;
    time inode_last_modified;

    type direct_blocks[INODE_NUM_DIRECT_BLOCKS];
    type single_indirect_block;
    type double_indirect_block;
    type triple_indirect_block;
};

struct directory{
    type inode_num_in_dir[ /*TODO*/];
    char* name[/*TODO*/];
};
