#include <stdio.h>
#include <stdlib.h>

#define PATH_SAMPLE_ARK_1 "../../samples/raw_mfcc_dt05_simu_DCUNET_t12_5.1.ark"
#define PATH_SAMPLE_SCP_1 "../../samples/raw_mfcc_dt05_simu_DCUNET_t12_5.1.scp"
#define PATH_SAMPLE_ARK_2 "../../samples/raw_mfcc_dt05_real_DCUNET_t12_5.1.ark"
#define PATH_SAMPLE_SCP_2 "../../samples/raw_mfcc_dt05_real_DCUNET_t12_5.1.scp"

int main() {

  FILE* fp=nullptr;

  fp = fopen(PATH_SAMPLE_ARK_1, "rb");
  if (!fp) {
    printf("ERROR::Can not open the file.\n");
    exit(-1);
  }

  char tmp_char;

  int cnt = 0;
  while (true) {
    fscanf(fp,"%c",&tmp_char);
    if(cnt < 30)
      printf("%d : %c\n", cnt,tmp_char);
    if(cnt > 8080 && cnt < 8135)
      printf("%d : %c\n", cnt,tmp_char);
    if(cnt > 16200 && cnt < 16240)
      printf("%d : %c\n", cnt,tmp_char);
    if (cnt > 20000)
      break;
    cnt++;
  }

  fclose(fp);

  return 0;
}