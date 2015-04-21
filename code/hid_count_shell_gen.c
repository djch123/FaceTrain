#include <stdio.h>
#include <string.h>

#define PRT_FMT "./facetrain -n test.net -1 ./../trainset/all_test1.list "\
				"-2 ./../trainset/all_test2.list -t ./../trainset/all_train.list "\
				"-e %d "\
				"-l %d "\
				"\n"

int main (int argc, char *argv[]) {
	int hid_count_min;
	int hid_count_max;
	int epochs;
	int delta;

  if (argc < 9) {
    printusage(argv[0]);
    return 1;
  }

  /*** Scan command line ***/
  for (int ind = 1; ind < argc; ind++) {

    /*** Parse switches ***/
    if (argv[ind][0] == '-') {
      switch (argv[ind][1]) {
        case 'e': epochs = atoi(argv[++ind]);
                  break;
        case 'h': hid_count_min = atoi(argv[++ind]);
                  break;
        case 'H': hid_count_max = atoi(argv[++ind]);
                  break;
        case 'd': delta = atoi(argv[++ind]);
                  break;
        default : printf("Unknown switch '%c'\n", argv[ind][1]);
        		  printusage(argv[0]);
        		  return 1;
                  break;
      }
    }
  }

  // printf("%d %d %d\n", hid_count, epochs_min, epochs_max);

  for (int i=hid_count_min; i<=hid_count_max; i+=delta){
  		printf(PRT_FMT, epochs, i);
  }
	return 0;
}

/*
./facetrain -n test.net -2 ./../trainset/all_test2.list -t ./../trainset/all_train.list -e 10
*/

printusage(prog)
char *prog;
{
  printf("USAGE: %s\n", prog);
  printf("       -e <number of minimum epochs>\n");
  printf("       -E <number of maximum epochs>\n");
  printf("       -h <count of hidden units>\n");
  printf("       -d <delta between epochs>\n");
}