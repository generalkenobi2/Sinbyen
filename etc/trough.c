#include <Sinbyen.h>
#include <item.h>

inherit "/std/item";

void configure() {
    ::configure();
       alter_identity(([
        Identity_Name           : "trough",
        Identity_Nouns          : ({ "trough" }),
    ]));
    add_description(({
        ({ 't', 0 }), "is filled with {{watery}water}.  It is charred and nicked from repeated use.",
        "It has been bolted into the stone flooring for added stability",
 
    }));
    set_craft(Craft_Excellent);
        set_shape(([
        Shape_Type              : Geometry_Block,
        Shape_Length            : 15.0,
        Shape_Width             : 4.0,
        Shape_Height            : 7.0,
    ]));
    add_proportion(([
        Element_Type            : Material_Oak,
        Element_Proportion      : 1.0,
        Element_Flags           : Element_Flag_Provide_Default_Color,
    ]));
    add_proportion(([
        Element_Type            : Material_Water,
        Element_Proportion      : 2.0,
    ]));
}

status get() {
        return True;
}
