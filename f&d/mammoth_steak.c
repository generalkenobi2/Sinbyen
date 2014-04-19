#include <Grinning_Cat.h>
#include <Sinbyen.h>
#include <item.h>

inherit Sinbyen_Comestible("Mammoth");

void configure() {
        ::configure();
		alter_identity(([
			Identity_Nouns          : ({ "mammoth steak", "steak" }),
		]));
        add_description("A truly massive mammoth steak.  Cooked medium well and lightly seasoned.");
        set_consume_message("Juicy but firm, the mammoth meat tastes fantastic!");
        set_servings(8);

}
