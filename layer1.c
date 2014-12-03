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
	return 0;
    }
    
    get_block(buffer, block_num);

    
}

bool read_inode(type inode_num, struct node* inodep){
    if(inode_num<1 || inode_num>NUM_OF_INODES){
	printf("WRONG INODE NUMBER\n");
	return 0;
    }
    type block_num = (inode_num-1)*(INODE_SIZE)/(BLOCK_SIZE) + 1;
    type offset = (inode_num-1)*(INODE_SIZE)%(BLOCK_SIZE); //Inode has to be multiple of block size
    read_block(nodep, block_num,offset,sizeof(struct inode));
}

    
    read_block(



    
