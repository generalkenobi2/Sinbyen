#include <Sinbyen.h>
#include <item.h>

inherit Sinbyen_Comestible("Fizzy_Base");

void configure() {
        ::configure();
        set_names(({ "{{dark purple}grape fizzy}", "grape fizzy", "fizzy" }));
        add_description("A tall bubbling grape flavoured beverage with a {{purple}purple} label.");
        set_consume_message("The sweet {{dark purple}grape} flavour is delightful.");
		add_material(Material_Grape);
}
