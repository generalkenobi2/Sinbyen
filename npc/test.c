#include <Enchysi_Daktylion.h>
#include <Sinbyen.h>
#include <autonomon.h>
#include <directions.h>
#include <instructor.h>
#include <speech.h>

inherit "usr/haiku.c";

inherit "/std/autonomon";

void configure() {
	::configure();
	set_culture_name("Farid");
}
