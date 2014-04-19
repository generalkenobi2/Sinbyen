#include <Sinbyen.h>
#include <items.h>
#include <room.h>
#include <trader.h>


inherit Sinbyen_Room("Map_Base");

inherit "/std/trader";

Trader_Functions(Map_Base)

void configure() {
	Map_Base::configure();
	trader::configure();
	set_short("Ralphgar's Furnishings");
	add_exit(Direction_North);
	add_exit(Direction_East);
	set_list_header_left("Item Description");
	set_list_header_right("Cost");
	set_haggle_optimum(75);
	set_buying_power(5000);
	set_inventory_attrition(25);
	set_stock(([
		(:	Sinbyen_Misc("sinbyen_bed")				:)	: 4,
		(:	Sinbyen_Misc("sinbyen_chair")			:)	: 8,
		(:	Sinbyen_Misc("sinbyen_table")			:)	: 4,
	]));
	set_operators(({
		Sinbyen_NPC("ralphgar"),
	}));
	set_operations(Trader_Shop);
	set_contents(({
		Sinbyen_NPC("ralphgar"),
	}));
}
