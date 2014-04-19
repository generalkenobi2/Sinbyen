#include <Sinbyen.h>
#include <items.h>
#include <room.h>
#include <Grinning_Cat.h>
#include <trader.h>


inherit Sinbyen_Room("Map_Base");

inherit "/std/trader";

Trader_Functions(Map_Base)

void configure() {
	Map_Base::configure();
	trader::configure();
	add_extension(Grinning_Cat_Support);
	set_short("The Grinning Cat Eatery of the City of Sinbyen");
	set_exit_flags(Direction_Northwest, Exit_Flag_Inobvious | Exit_Flag_Soundproof | Exit_Flag_Requires_Intangibility);
	set_exit_flags(Direction_Southwest, Exit_Flag_Inobvious | Exit_Flag_Soundproof | Exit_Flag_Requires_Intangibility);
	set_exit_flags(Direction_Southeast, Exit_Flag_Inobvious | Exit_Flag_Soundproof | Exit_Flag_Requires_Intangibility);
	add_exit(Direction_West);
	add_exit(Direction_South);
	
	add_description(([
		Description_Type                                : Description_Type_Simple,
		Description_Content                             : ({
			"this is the Grinning Cat Eatery of the City of Sinbyen",
		}),
		Description_Order                               : Description_Order_Extremely_Early,
	]));
	add_description(([
		Description_Type                                : Description_Type_Simple,
		Description_Content                             : ({
			Description(([
			    Description_Type                        : Description_Type_Viewer_Condition,
                Description_Index                       : ([
                    Condition_Type_Code                 : Condition_Type_Hearing,
                ]),
                Description_Content                     : "The air is aglow with the scent of freshly baked pies, pastas, and other treats",
			])),
		}),
		Description_Order                               : Description_Order_Early,
	]));
	add_terrain(Terrain_Building);
	set_operators(({
		Sinbyen_NPC("perry"),
	}));
	set_contents(({
		Sinbyen_NPC("perry"),
	}));
	set_stock(([
		Grinning_Cat_Comestible("acqua")                   :20,
		Grinning_Cat_Comestible("acqua_frizzante")         :20,
		Grinning_Cat_Comestible("antipasto")               :20,
		Grinning_Cat_Comestible("artichoke")               :20,
		Grinning_Cat_Comestible("bagel_butter")            :20,
		Grinning_Cat_Comestible("bagel_cream_cheese")      :20,
		Grinning_Cat_Comestible("bagel_plain")             :20,
		Grinning_Cat_Comestible("blt_sandwich")            :20,
		Grinning_Cat_Comestible("broccoli_cheese_soup")    :20,
		Grinning_Cat_Comestible("calamari")                :20,
		Grinning_Cat_Comestible("canoli")                  :20,
		Grinning_Cat_Comestible("chicken_noodle_soup")     :20,
		Grinning_Cat_Comestible("chili")                   :20,
		Grinning_Cat_Comestible("chocolate_cake")          :20,
		Grinning_Cat_Comestible("chocolate_strawberry")    :20,
		Grinning_Cat_Comestible("club_sandwich")           :20,
		Grinning_Cat_Comestible("fetuccini_alfredo")       :20,
		Grinning_Cat_Comestible("garlic_bread")            :20,
		Grinning_Cat_Comestible("gelato")                  :20,
		Grinning_Cat_Comestible("lasagne")                 :20,
		Grinning_Cat_Comestible("manicotti")               :20,
		Grinning_Cat_Comestible("mimosa")                  :20,
		Grinning_Cat_Comestible("pie_apple")               :20,
		Grinning_Cat_Comestible("pie_cherry")              :20,
		Grinning_Cat_Comestible("pie_peach")               :20,
		Grinning_Cat_Comestible("pollo_parmingiano")       :20,
		Grinning_Cat_Comestible("salad")                   :20,
		Grinning_Cat_Comestible("sea_kelp_salad")          :20,
		Grinning_Cat_Comestible("spaghetti")               :20,
		Grinning_Cat_Comestible("stromboli")               :20,
		Grinning_Cat_Comestible("truffle")                 :20,
		Grinning_Cat_Comestible("vino_blanch")             :20,
		Grinning_Cat_Comestible("vino_del_casa")           :20,
		Grinning_Cat_Comestible("vino_rosso")              :20,
		Grinning_Cat_Comestible("apple_sushi")             :20,
		Grinning_Cat_Comestible("cucumber_sushi")          :20,
		Grinning_Cat_Comestible("eel_sushi")               :20,
		Grinning_Cat_Comestible("mahi_sashimi")            :20,
		Grinning_Cat_Comestible("prawn_sushi")             :20,
		Grinning_Cat_Comestible("salmon_sashimi")          :20,
		Grinning_Cat_Comestible("salmon_sushi")            :20,
		Grinning_Cat_Comestible("sea_food_salad")          :20,
		Grinning_Cat_Comestible("spider_crab_sushi")       :20,
		Grinning_Cat_Comestible("yellow_tail_sushi")       :20,
		Grinning_Cat_Comestible("yellow_tail_sashimi")     :20,
	]));
	set_list_header_left("Cuisine");
	set_list_header_right("Price");
	set_haggle_optimum(75);
	set_buying_power(1000);
	set_inventory_display(({ "menu" }), Skill_Norska);
	set_inventory_static(True);
	set_operations(Trader_Tavern);
}
