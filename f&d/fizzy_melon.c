#include <Sinbyen.h>
#include <item.h>

inherit Sinbyen_Comestible("Fizzy_Base");

void configure() {
        ::configure();
        set_names(({ "{{dark green}melon fizzy}", "melon fizzy", "fizzy" }));
        add_description("A tall bubbling melon flavoured beverage with a {{dark green}green} label.");
        set_consume_message("The sweet {{dark green}melon} flavour is delightful.");
		add_material(Material_Watermelon);
}
