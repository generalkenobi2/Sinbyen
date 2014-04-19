#include <Sinbyen.h>
#include <item.h>

inherit Sinbyen_Comestible("Fizzy_Base");

void configure() {
        ::configure();
        set_names(({ "{{light green}lime fizzy}", "lime fizzy", "fizzy" }));
        add_description("A tall bubbling lime flavoured beverage with a {{light green}green} label.");
        set_consume_message("The sweet and sour {{light green}lime} flavour is delightful.");
		add_material(Material_Lime);
}
