using namespace std;

#include <iostream>

const int max_keyID_len = 16;

struct keyID_struct
{
 char keyID[max_keyID_len];
 keyID_struct *next;
};

keyID_struct *start;
keyID_struct *ende;
keyID_struct *cur;

main()
{
 start = NULL;

 const int n = 10240;
 char line[n];

 char keyID[max_keyID_len];

 int lineNr = 0;

 while( cin.getline(line,n) )
 {
   int i = 0;
   int anzahlDoppelPunkte = 0;

   lineNr++;

   while ( line[i] != '\0' )
   {
     if (line[i++] == ':')
     {
       anzahlDoppelPunkte++;

       if ( i != 4 || line[0] != 's'
                   || line[1] != 'i'
                   || line[2] != 'g' )
       {
         i = 0;
         line[i] = '\0';
       }
       break;
     }
   }

   int anzahl2 = anzahlDoppelPunkte;
   int i2      = i;

   while ( line[i2] != '\0' )
   {
     if (line[i2++] == ':')
       anzahl2++;

     if (anzahl2 == 9)
     {
       if (line[i2] != '[')
       {
         i = 0;
         line[i] = '\0';
       }
       break;
     }
   }

   while ( line[i] != '\0' )
   {
     if (line[i++] == ':')
       anzahlDoppelPunkte++;

     if (anzahlDoppelPunkte == 4)
     {
       break;
     }
   }

   i2 = 0;

   while ( line[i] != '\0' )
   {
     if (line[i] == ':')
     {
       if ( i2 != max_keyID_len )
       {
         cerr << "Zeile Nr. " << lineNr << endl;
         cerr << "FEHLER: keyID_len = " << i2 << endl;
         return -1;
       }

       cur = start;

       if (start == NULL)
       {
         start = new keyID_struct;
         ende = start;

         for (int x = 0; x < max_keyID_len; x++)
           start->keyID[x] = keyID[x];

         start->next = NULL;
         break;
       }

       int append_flag = 1;

       while (cur && append_flag)
       {
         int gleich_flag = 1;

         for (int x = 0; x < max_keyID_len; x++)
         {
           if (cur->keyID[x] != keyID[x])
           {
             gleich_flag = 0;
             break;
           }
         }

         if (gleich_flag)
         {
           append_flag = 0;
           break;
         }

         cur=cur->next;
       }

       if (append_flag)
       {
         ende->next = new keyID_struct;
         ende=ende->next;

         for (int x = 0; x < max_keyID_len; x++)
           ende->keyID[x] = keyID[x];

         ende->next = NULL;
       }
       break;
     }

     if (i2 < max_keyID_len)
     {
       keyID[i2++] = line[i];
     }

     i++;
   }

 } // while getline

 cur = start;

 while (cur)
 {
   cout << "gpg --trust-model direct --keyserver pgp.surfnet.nl --recv ";

   for (int x = 0; x < max_keyID_len; x++)
     cout << cur->keyID[x];

   cout << endl;

   cur=cur->next;
 }

 return 0;
}
