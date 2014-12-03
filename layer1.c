#include "global.h"
#include "layer0.h"

//read_inode
//free_inode
//allocate_inode
//write_inode
//fill_free_inode_list

//read_block
//write_block
//allocate_block
//free_block
//fill_free_block_list

int read_block(void* buffer, type block_num, type offset, type size){
    if(offset >= BLOCK_SIZE){
	printf("offset out of bound");
	return -1;
    }
    
    if(offset+size > BLOCK_SIZE){
	printf("some data might not be read. read size > block size.\n");
	size = BLOCK_SIZE - offset;
    }

    // get whole block then extract offset
    char read_buffer[BLOCK_SIZE]; 
    get_block(read_buffer, block_num);
    memcpy(buffer, read_buffer+offset, size);

    return size;
}

bool read_inode(type inode_num, struct node* inodep){
    if(inode_num<1 || inode_num>NUM_OF_INODES){
	printf("WRONG INODE NUMBER\n");
	return 0;
    }
    type block_num = (inode_num-1)*(INODE_SIZE)/(BLOCK_SIZE) + 1;
    type offset = (inode_num-1)*(INODE_SIZE)%(BLOCK_SIZE); //inode has to be multiple of block size
    read_block(nodep, block_num,offset,sizeof(struct inode));
    return 1;
}

bool write_block(const void* buffer, type block_num, type offset, type size){
    if(offset >= BLOCK_SIZE){
	printf("offset out of bound");
	return 0;
    }

    if(offset+size > BLOCK_SIZE){
	printf("Can not write all data. data size > block size.\n");
	return 0;
    }

    char read_buffer[BLOCK_SIZE];
    get_block(read_buffer, block_num);
    memcpy(read_buffer+offset, buffer, size);

    put_block(buffer, block_num);

    return 1;
}




    
