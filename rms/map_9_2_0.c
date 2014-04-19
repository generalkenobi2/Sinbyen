#include <Sinbyen.h>
#include <items.h>
#include <room.h>
#include <trader.h>
#include <Togrek.h>
#include <Yathryn.h>
#include <Armaments_of_Calibra.h>
#include <Shatterspire.h>
#include <Northlands.h>
#include <Xi_Feng_Ming.h>
#include <Rajan_Windship.h>

inherit Sinbyen_Room("Map_Base");

inherit "/std/trader";

Trader_Functions(Map_Base)


void configure() {
    Map_Base::configure();
    trader::configure();
    set_short("Dataro's Cloaks N' Capes");
    add_exit(Direction_South);
    set_list_header_left("Item Description");
    set_list_header_right("Cost");
    set_haggle_optimum(75);
    set_buying_power(10000);
    set_inventory_attrition(25);
    set_stock(([
               (: random_element(([
                    Yathryn_Armour("eislinzal_cloak_1")         : 100,
                    Yathryn_Armour("eislinzal_cloak_2")         : 75,
                    Yathryn_Armour("eislinzal_cloak_3")         : 50,
                    Yathryn_Armour("glomschal")                 : 5,
                    Togrek_Armour("woolen_cloak")               : 100,
                    Armaments_of_Calibra_Armour("kineitid_new") : 20,
                    Shatterspire_Armour("holocaust_cloak")      : 50,
                    Xi_Feng_Ming_Armour("cloak_of_holding")     : 50,
                    Northlands_Armour("furred_cloak")           : 100,
                    Northlands_Armour("giant_cloak")            : 75,
                    Northlands_Armour("yeti_cloak")             : 100,
                    Rajan_Windship_Armour("death_cloak")        : 20,
                ])) :)                                          : 15, 
    ]));
    set_operators(({
        Sinbyen_NPC("dataro"),
    }));
    set_operations(Trader_Shop);
    
    set_contents(({
        Sinbyen_NPC("dataro"),
    }));
}
