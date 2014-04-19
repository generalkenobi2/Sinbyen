#include <item.h>
inherit LS_Misc("trashcan");

void configure() {
	::configure();
	set_trashcan_checker_name("a large {{brown}thond}");
	string checker_name = query_trashcan_checker_name();
	set_trashcan_check_message( ({ ({ 'a', checker_name }), "stomps in and opens", ({ 't', this_object() }) }) );
	set_trashcan_nofind_message( ({ ({ 't', checker_name }), "smiles and stomps back out" }) );
	set_trashcan_find_message( ({ ({ 't', checker_name }), "collects the garbage in a {{black}sack}, hefts it over his shoulder, and stomps out" }) );
}
