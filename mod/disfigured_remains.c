#include <item.h>

inherit "/std/remains";

descriptor remains_element_process(descriptor dxr) {
        dxr = ::remains_element_process(dxr);
        if(Element_Query(dxr, Element_Part) != Part_Bulk)
                return 0;
        descriptor out = copy(dxr);
        Element_Flag_On(out, Element_Flag_Suppress_Race);
        return out;
}

                                                        
void configure() {
        ::configure();
        add_description(Description_Type_Generic);
        alter_identity(([    
            Identity_Nouns                : ({({"flesh and {{white}bone}", 0, Seeable_Order_Early }),({ "bone", 0, Seeable_Order_Early }), ({"flesh", 0, Seeable_Order_Early })}),
            Identity_Flags                : Identity_Flag_Suppress_Elements,
        ]));
        alter_identity(Identity_Adjunct_Nouns, ({ "pile" }));
        set_craft(Craft_Raw);
        set_mass_capacity(10000);
        set_volume_capacity(10000);
        set_remains_decay(True);
        set_remains_accept_objects(True);
        set_remains_accept_money(True);
        set_remains_create_message(({ 0, ({ "stop", 0 }), "moving, and", ({ "collapse", 0 }), "in a haphazard pile of flesh and bone" }));
        set_remains_decay_away_message(({ 0, ({ "dissolve", 0 }), "slowly into the air" }));
}
