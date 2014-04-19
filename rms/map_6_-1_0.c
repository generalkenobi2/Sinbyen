#include <Sinbyen.h>
#include <items.h>
#include <room.h>
#include <trader.h>
#include <traits.h>

inherit Sinbyen_Room("Map_Base");

inherit "/std/trader";

Trader_Functions(Map_Base)

status leather_equipment_only(object obj) {
        return obj->query_property(Prop_Metal);
}

void configure() {
    Map_Base::configure();
    trader::configure();
    add_terrain(Terrain_Building);
    set_short("Primbal's Armour");
    add_description(([
        Description_Type                                : Description_Type_Simple,
        Description_Content                             : ({
            "this is",'a',"smithing shop",
        }),
        Description_Order                               : Description_Order_Very_Early,
    ]));
    add_description(([
        Description_Type                                : Description_Type_Simple,
        Description_Content                             : ({
            "the",
                Description(([
                    Description_Type                    : Description_Type_Viewer_Condition,
                    Description_Index                   : ([
                        Condition_Type_Code             : Condition_Type_Tactile_Sensation,
                    ]),
                    Description_Content                 : "{{shadowfire}scorching}",
                ])),
            "air is thick with smoke",
                Description(([
                    Description_Type                    : Description_Type_Viewer_Condition,
                    Description_Index                   : ([ 
                    Condition_Type_Code                 : Condition_Type_Material_Respirable,
                    Condition_Info                      : Material_Smoke, 
                    Condition_Flags                     : Condition_Flag_Inverse ]),
                    Description_Content                 : ", making it difficult to breathe",
            
                ])),
            ".",
        }),
        Description_Order                               : Description_Order_Early,
    ]));
    set_contents(([
        Sinbyen_Misc("forge")                           : 1,
        Sinbyen_NPC("primbal")                          : 1,
        Sinbyen_Misc("bellows")                         : 1,
        Sinbyen_Misc("anvil")                           : 1,
        Sinbyen_Misc("trough")                          : 1,
    ]));
    set_list_header_left("Item Description");
    set_list_header_right("Cost");
    set_haggle_optimum(75);
    set_buying_power(10000);
    set_inventory_attrition(25);
    set_specialty_rule(#'leather_equipment_only);
    set_operators(({
        Sinbyen_NPC("primbal"),
    }));
    set_stock(([
        (: Random_Item_Armour               :)     : 4,
        (: Sinbyen_Armour("steel_boots")    :)     : 4,
        (: Sinbyen_Armour("steel_gauntlets"):)     : 4,
        (: Sinbyen_Armour("steel_halfsuit") :)     : 2,
        (: Sinbyen_Armour("steel_helm")     :)     : 4,
        (: Sinbyen_Armour("steel_suit")     :)     : 1,
    ]));
    set_operations(Trader_Tavern | Trader_Appraise | Trader_Repair | Trader_Resize | Trader_Evaluate | Trader_List);
}
