#include <stdio.h>
#include <stdlib.h>

#define PATH_SAMPLE_ARK_1 "../../samples/raw_mfcc_dt05_simu_DCUNET_t12_5.1.ark"
#define PATH_SAMPLE_SCP_1 "../../samples/raw_mfcc_dt05_simu_DCUNET_t12_5.1.scp"
#define PATH_SAMPLE_ARK_2 "../../samples/raw_mfcc_dt05_real_DCUNET_t12_5.1.ark"
#define PATH_SAMPLE_SCP_2 "../../samples/raw_mfcc_dt05_real_DCUNET_t12_5.1.scp"

void read_1(FILE* fp);
void read_first_item(FILE* fp);

#define IND 22
#define FORMAT 6

int main() {

  FILE* fp=nullptr;

  fp = fopen(PATH_SAMPLE_ARK_1, "rb");
  if (!fp) {
    printf("ERROR::Can not open the file.\n");
    exit(-1);
  }

  read_1(fp);
  read_first_item(fp);

  fclose(fp);

  return 0;
}

void read_first_item(FILE* fp) {

  fseek(fp, 0, SEEK_SET);

  char tmp_char;
  double tmp_float;
  double tmp_double;
  double tmp_int;
  int cnt = 0;

  while (true) {
    if (cnt < IND+FORMAT) {
      fscanf(fp, "%c", &tmp_char);
      printf("%d : %c\n", cnt, tmp_char);
      cnt++;
    }
    else {
      fseek(fp, IND + FORMAT, SEEK_SET);
      fscanf(fp, "%c", &tmp_char);
      printf("%d char : %c\n", cnt, tmp_char);

      fseek(fp, IND + FORMAT, SEEK_SET);
      fscanf(fp, "%lf", &tmp_double);
      printf("%d double : %lf\n", cnt, tmp_double);

      fseek(fp, IND + FORMAT, SEEK_SET);
      fscanf(fp, "%f", &tmp_float);
      printf("%d float : %f\n", cnt, tmp_float);

      fseek(fp, IND + FORMAT, SEEK_SET);
      fscanf(fp, "%d", &tmp_int);
      printf("%d int : %d\n", cnt, tmp_int);
      break;
    }

  }
  printf("---------------------------\n");
}

void read_1(FILE* fp) {

  fseek(fp, 0, SEEK_SET);

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
  printf("---------------------------\n");
}
