#include <Sinbyen.h>
#include <item.h>

inherit Sinbyen_Comestible("Fizzy_Base");

void configure() {
        ::configure();
        set_names(({ "{{orange}orange fizzy}", "orange fizzy", "fizzy" }));
        add_description("A tall bubbling orange flavoured beverage with an {{orange}orange} label.");
        set_consume_message("The sweet {{orange}orange} flavour is delightful.");
		add_material(Material_Orange);
}
