#include <Sinbyen.h>
#include <item.h>
#include <Public.h>

inherit "/std/item";

descriptor steel() {
	return  Description(([
                Description_Type   : Description_Type_Element_Name,
                Description_Index  : Element(([
                    Element_Type   : Material_Steel,
                    Element_Color  : "dark gray",
                    Element_Flags  : Element_Flag_Suppress_Color_Name,
                ])),
            ]));
}

mixed query_room_desc() {
    mixed array content = ({
       'a',"{{dark gray}massive",steel(),({ 'n',this_object()}),"} takes up a large portion of the room and extends through the ceiling.",
    });
    return Description(([
        Description_Type                                : Description_Type_Simple,
        Description_Order                               : Description_Order_Slightly_Early,
        Description_Content                             : content,
    ]));
}
void configure() {
    ::configure();
       alter_identity(([
        Identity_Name           : "forge",
        Identity_Nouns          : ({ "forge" }),
        Identity_Adjectives     : ({"massive"}),
    ]));
    set_indestructible(True);
    add_description(({
        ({ 't', 0 }), "{{holy fire}burns brightly}, releasing copious amounts of heat",
    }));
    add_description(({
        "nearly the entire column is covered with {{black}black soot}",
    }));
    set_craft(Craft_Excellent);
        set_shape(([
        Shape_Type              : Geometry_Hollow_Column,
        Shape_Radius            : 13.0,
        Shape_Height            : 60.0,
        Shape_Thickness         : 3.0,
    ]));
    add_proportion(([
        Element_Type            : Material_Steel,
        Element_Proportion      : 1.0,
        Element_Color           : "dark gray",
    ]));
}

void object_received(object obj, object who) {
	if(obj->query_indestructible()) {
		message(({ "the {{fiery}forge flames} lick about", ({ 't', obj }), "for a moment, then retreat from", ({ 'o', obj })}));
		return;
	}
	if(obj->query_property(Prop_Explosive))
		message(({({ 't', obj }), ({ "explode", 0 }), "in a {{white}bright flash} within the forge" }));
	else if(obj->query_property(Prop_Flammable))
		message(({({ 't', obj }), ({ "burst", 0 }), "into {{fiery}flames} and", ({ "burn", obj }), "away within the forge" }));
	else if(obj->query_phase() != Matter_Phase_Solid)
		message(({({ 't', obj }), ({ "boil", 0 }), "away in the forge" }));
	else
		message(({({ 't', obj }), ({ "melt", 0 }), "away in the forge" }));
	obj->move(Public_Room("trash"));
	obj->remove();
}
