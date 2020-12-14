/* Rafael Arce Nazario*/

#include "HashTable.h"
using namespace std;

#include <iostream>
#include <fstream>
#define CATCH_CONFIG_MAIN
#include "HashTable.h"
#include <vector>
#include "catch_amalgamated.hpp"
using namespace std;



TEST_CASE( "Pushing and popping to the AStack", "[AStack]" ) {
    HashTable H;
    vector< pair<string,int> > tmp01 {
        {"maiz",23},{"refresco",245},{"lechuga",99},
        {"acerolas",123},{"agua",105},{"mayonesa",299},
        {"recao",75},{"manzana",125},{"pera",99}
    };
    for (auto e: tmp01) H.insert(e.first, e.second);

    cout << H.toString() << endl;


    vector< pair<string,int> > tmp02 {
            {"pasta",133},{"ginebra",2125},{"vodka",2099},
            {"salsa",100},{"ketchup",225},{"cebolla",59},
            {"ajo",110},{"jugo",345},{"fosforos",159},
    };
    for (auto e: tmp02) H.insert(e.first, e.second);
    cout << H.toString() << endl;

    H.remove("maiz");
    H.remove("salsa");
    cout << H.toString() << endl;

    CHECK(H.find("maiz") == -1);
    CHECK(H.find("ginebra") == 2125);


}