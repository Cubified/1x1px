/*
 * 1x1px.c: a simple utility to generate 1x1-pixel PNG images
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define STB_NO_LINEAR
#define STB_NO_HDR
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "stb_image_write.h"

char *str_substring(char *str, int start, int size){
  char *out = malloc(size);
  int i = 0;
  for(char *c=str+start;i<size;c++){
    out[i] = *c;
    i++;
  }
  return out;
}

int main(int argc, char *argv[]){
  if(argc < 2){
    printf("Usage: 1x1px [color]\n");
    exit(1);
  }

  char *color_hash = argv[1];

  if(strlen(color_hash) != 7 || color_hash[0] != '#'){
    printf("Error: color must be in format #RRGGBB\n");
    exit(2);
  }

  char *color = malloc(6);
  char *filename = malloc(10);
  int i = 0;
  for(char *c=color_hash+1;*c;c++){
    color[i]    = *c;
    filename[i] = *c;
    i++;
  }
  strcat(filename,".png");

  unsigned char *data = malloc(3);
  data[0] = strtol(str_substring(color,0,2),NULL,16);
  data[1] = strtol(str_substring(color,2,2),NULL,16);
  data[2] = strtol(str_substring(color,4,2),NULL,16);

  stbi_write_png(filename,1,1,3,data,0);

  char cwd[1024];
  getcwd(cwd,sizeof(cwd));

  char *quiet = (argc == 3 ? argv[2] : NULL);

  if(quiet == NULL){
    printf("Color %s successfully saved to %s/%s\n",color_hash,cwd,filename);
  }

  free(color);
  free(filename);
  free(data);

  return 0;
}
