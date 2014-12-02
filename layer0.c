#include "global.h"

bool get_block(void* buffer, type block_num){
    lseek(fs_fd, block_num*BLOCK_SIZE, SEEK_SET);
    int size = read(fs_fd, buffer, BLOCK_SIZE);
    if(size<0){
	perror("GET BLOCK ERROR ");
	return 0;
    }
    return 1;
}

bool put_block(void* buffer, type block_num){
    lseek(fs_fd, block_num*BLOCK_SIZE, SEEK_SET);
    int size = write(fs_fd, buffer, BLOCK_SIZE);
    if(size < 0){
	perror("PUT BLOCK ERROR ");
	return 0;
    }
    return 1;
}

    
