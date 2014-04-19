#include <colors.h>
#include <files.h>
#include <item.h>
#include <Sinbyen.h>

inherit "/std/item";

void everfull_quiver_ammo_do_launch_move(mapping args) {
	object obj = args["weapon"];
	object who = args["user"];
	object target = args["target"];
	if(target)
		target->message(([
			Message_Content     : ({
				({ 't', obj }), ({ "disappear", obj }),
			}),
			Message_Senses      : Message_Sense_Visual | Message_Sense_Tactile_For_Source | Message_Sense_Tactile_For_Participants,
		]));
	if(!target || environment(who) != environment(target))
		who->message(([
			Message_Content     : ({
				({ 't', obj }), ({ "disappear", obj }),
			}),
			Message_Senses      : Message_Sense_Visual,
		]));
	safe_destruct(obj);
}

void everfull_quiver_schedule_destruct(object obj) {
	call_out("everfull_quiver_destruct", 1, obj);
}

void everfull_quiver_destruct(object obj) {
	if(!obj)
		return;
	obj->user_message(([
	    Message_Content         : ({
	    	0, ({ "disappear", 0 }),
		}),
		Message_Senses          : Message_Sense_Visual | Message_Sense_Tactile_For_Source | Message_Sense_Tactile_For_Participants,
	]));
	safe_destruct(obj);
}

varargs object array query_everfull_quiver_duplicable_contents(object launcher) {
	object array out = ({});
	foreach(object obj : all_inventory()) {
		if(obj->query_unique())
			continue;
		if(obj->query_indestructible())
			continue;
		if(obj->id("NR", Knowledge_Known))
			continue;
		if(obj->query_info("Replicate"))
			continue;
		if(obj->query_property_proportion(Prop_Primal) > 0)
			continue;
		if(launcher && !launcher->weapon()->query_valid_ammunition(obj))
			continue;
		if(obj->query_weapon_instantiated() && obj->weapon()->query_ranged() == Null)
			continue;
		out += ({ obj });
	}
	return out;
}

object everfull_quiver_value_replace_contained_ammo(mapping args) {
	if(query_any_realm("NM", this_object()))
		return 0;
	object launcher = args["launcher"];
	if(!launcher)
		return 0;
	object array poss = query_everfull_quiver_duplicable_contents(launcher);
	if(!sizeof(poss))
		return 0;
	object base = random_element(poss);
	if(!base)
		return 0;
	object obj = 0;
	catch(obj = new(base));
	if(!obj)
		return 0;
	object who = args["who"];
	object blueprint = load_object(load_name(this_object()));
	obj->perform_dynamic_insert(who, base->perform_dynamic_extract(who));
	base->set_info("Replicated_Item", True);
	obj->set_info("Replicate", True);
	obj->set_unkeepable(True);
	obj->set_dest_on_drop(True);
	obj->set_value(0);
	obj->add_property(Prop_Manifestation);
	obj->add_hook(Do_Launch_Move, func(blueprint, "everfull_quiver_ammo_do_launch_move"));
	base->do_replicate_degradation();
    obj->do_replicate_degradation();
    object array extensions = ({});
    foreach(string type, mixed ext : base->query_extensions())
        if(arrayp(ext))
            extensions += ext;
        else
            extensions += ({ ext });
    foreach(string type, mixed ext : obj->query_extensions())
        if(arrayp(ext))
            extensions += ext;
        else
            extensions += ({ ext });
    extensions -= ({ 0 });
    extensions = unique(extensions);
    extensions->do_replicate_degradation();
	blueprint->everfull_quiver_schedule_destruct(obj);
	obj->move(this_object(), Move_Flag_Ignore_Mass_Capacity | Move_Flag_Ignore_Volume_Capacity | Move_Flag_Usage_Silent | Move_Flag_Failure_Destructs);
	return obj;
}

void everfull_quiver_at_contained_ammo_replaced(mapping args) {
	object who = args["who"];
	if(query_user() == who)
		user_message(([
		    Message_Content     : ({
		    	"a {{auroric}shimmer of auroric radiance} runs from the bottom of", 0, "to the top",
			}),
			Message_Flags       : Message_Flag_Exclude_Source,
			Message_Senses      : Message_Sense_Astral,
		]));
	else
		message(([
		    Message_Content     : ({
		    	"a {{auroric}shimmer of auroric radiance} runs from the bottom of", 0, "to the top",
			}),
			Message_Senses      : Message_Sense_Astral,
		]));
	descriptor manip = args["manipulator"];
	mixed limb_index = Manipulator_Query(manip, Manipulator_Limb_Index);
	if(intp(limb_index) && limb_index >= 0)
		if(who->query_limb_provides_touch(limb_index))
			who->display(([
	    		Message_Content : ({
					0, ({ "feel", 0 }), "something come into existence within", ({ 't', this_object() }), "just in time for",
					({ 'o', 0 }), "to grasp", ({ 'o', this_object() }),
				}),
				Message_Senses  : Message_Sense_Tactile,
			]));
	object obj = args["original"];
	if(obj) {
		float special = max(obj->query_property_proportion(Prop_Magical), obj->query_property_proportion(Prop_Psychic), obj->query_property_proportion(Prop_Hyperreactive));
		float cost = 0.5 + special * 10;
		if(special > 0)
			damage_durability(special * special * 50);
		who->add_spell_points(-cost);
	}
}

void everfull_quiver_at_contained_ammo_replace_fail(mapping args) {
	safe_destruct(args["what"]);
}

void configure() {
	::configure();
	alter_identity(Identity_Name, "everfull quiver");
	alter_identity(Identity_Known_Value, 2000);
	set_identify_skills(([
		Skill_Legend_Lore       : 50,
		Skill_Arcane_Lore       : 60,
	]));
	add_description(Description_Type_Generic);
	add_known_description(({
	    'v', ({ "recognize", 'v' }), ({ 'o', 0 }), "as an Everfull Quiver, bearing enchantments that cause it to be such that, "
	    "when one attempts to draw an item of ammunition that has been placed in the quiver, for purposes of firing, one instead "
	    "receives an evanescent magickal duplicate that performs identically.",
	}));
	set_craft(random_element(([
	    Craft_Very_Poor         : 1,
	    Craft_Poor              : 2,
	    Craft_Fair              : 3,
	    Craft_Good              : 10,
	    Craft_Excellent         : 10,
	    Craft_Exquisite         : 3,
	])));
	armour()->set_armour_type(Armour_Type_Quiver);
	armour()->set_race(Random_Race_Folk);
	armour()->set_autonomon_adapt(Race_Category_Required("people"));
	string color = Random_Color(({
		Select_Include_All,
		Select_Exclude_Name("silver"),
		Select_Exclude_Name("silvery"),
	}));
	add_proportion(([
		Element_Type            : Material_Leather,
		Element_Proportion      : 1.0,
		Element_Color           : color,
		Element_Flags           : Element_Flag_Provide_Default_Color,
	]));
	add_proportion(([
		Element_Type            : Material_Silver,
		Element_Proportion      : 0.1,
		Element_Part            : Part_Inlay,
	]));
	add_proportion(([
		Element_Type            : Material_Dweomer,
		Element_Proportion      : 0.6,
	]));
	add_hook(Value_Replace_Contained_Ammo, #'everfull_quiver_value_replace_contained_ammo);
	add_hook(At_Contained_Ammo_Replaced, #'everfull_quiver_at_contained_ammo_replaced);
	add_hook(At_Contained_Ammo_Replace_Fail, #'everfull_quiver_at_contained_ammo_replace_fail);
	set_global_rarity(Rarity_Rare);
}
