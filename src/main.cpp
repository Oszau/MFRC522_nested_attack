/*30-03-17*****************************************************************************************************
***************************************************************************************************************
**                                                                                                           **
**                                                 main.cpp                                                  **
**                                                                                                           **
***************************************************************************************************************
**************************************************************************************************************/

#include "MFrec.h"

void cmd() { printf("CMD: ./crack A 63 6\n"); }

//int main()
int main(int argc, char *argv[])
{
  if(argc!=4) { cmd(); return 1; }
  uint8_t find_key = *argv[1];
  uint8_t valid_sector = atoi(argv[2]); if(valid_sector < 0 || valid_sector > 63) { cmd(); return 1; }
  uint8_t shadow_key = atoi(argv[3]); if(shadow_key < 0 || shadow_key > 63) { cmd(); return 1; }

    MFrec com;

    //  (command, exploit addr (block with known key), attack addr (key to recover), opt key for exploit bloc)
    //com.crackKey( AUTHENT_A, 63, 6 );

    if(find_key == 'A' || find_key == 'a') com.crackKey( AUTHENT_A, valid_sector, shadow_key );
    else if(find_key == 'B' || find_key == 'b') com.crackKey( AUTHENT_B, valid_sector, shadow_key);
         else { com.stop(); return 1; }

    com.stop();

    return 0;

}
