#include <Sinbyen.h>
#include <item.h>
#include <autonomon.h>
#include <Public.h>
#include <affiliation.h>
#include <aggression.h>
#include <alignment.h>
#include <ambulate.h>
#include <attack_form.h>
#include <autoheal.h>
#include <autonomon.h>
#include <balance.h>
#include <belonging_save.h>
#include <call.h>
#include <clone.h>
#include <command.h>
#include <communication.h>
#include <compare.h>
#include <config.h>
#include <culture.h>
#include <depictions.h>
#include <die.h>
#include <directions.h>
#include <display.h>
#include <distribution.h>
#include <effects.h>
#include <encumbrance.h>
#include <entourage.h>
#include <environmental_damage.h>
#include <exits.h>
#include <experience.h>
#include <extant.h>
#include <functionlist.h>
#include <inherit_list.h>
#include <interval.h>
#include <invis.h>
#include <learning.h>
#include <learning_source.h>
#include <locate_name.h>
#include <lpctypes.h>
#include <modifier.h>
#include <modifier_group.h>
#include <move.h>
#include <movement.h>
#include <notify.h>
#include <quotes.h>
#include <realtime.h>
#include <relationships.h>
#include <remove.h>
#include <senses.h>
#include <services_defer_load.h>
#include <services_heart_beat.h>
#include <services_link.h>
#include <services_npc_handler.h>
#include <services_reload_storage.h>
#include <services_route.h>
#include <services_save.h>
#include <services_time.h>
#include <specialty.h>
#include <specialty_access.h>
#include <subjects.h>
#include <thought.h>
#include <timed.h>
#include <usage.h>
#include <versus.h>
#include <add_attacker.h>
#include <aggression.h>
#include <aliasing.h>
#include <alignment.h>
#include <altitude.h>
#include <ambulate.h>
#include <anatomies.h>
#include <areas.h>
#include <attack_form.h>
#include <attributes.h>
#include <autoheal.h>
#include <caust.h>
#include <check_activity.h>
#include <combat.h>
#include <command.h>
#include <compare.h>
#include <config.h>
#include <configuration.h>
#include <culture.h>
#include <damage_type_skill_effect.h>
#include <damage_types.h>
#include <defense_form.h>
#include <depictions.h>
#include <die.h>
#include <diets.h>
#include <directions.h>
#include <distribution.h>
#include <energy.h>
#include <environmental_damage.h>
#include <exits.h>
#include <explore.h>
#include <exposure.h>
#include <extant.h>
#include <geometry.h>
#include <harm_skills.h>
#include <hooks.h>
#include <hylosoma.h>
#include <interactions.h>
#include <invis.h>
#include <languages.h>
#include <limbs.h>
#include <list_array.h>
#include <listing.h>
#include <lpctypes.h>
#include <master.h>
#include <materials.h>
#include <message.h>
#include <metabolism.h>
#include <microtimed.h>
#include <modifier.h>
#include <modifier_group.h>
#include <move.h>
#include <names.h>
#include <opponent_track.h>
#include <organs.h>
#include <path.h>
#include <process.h>
#include <projects.h>
#include <properties.h>
#include <queue_path.h>
#include <race.h>
#include <races.h>
#include <realtime.h>
#include <security.h>
#include <services_speed.h>
#include <sex.h>
#include <skills.h>
#include <stun.h>
#include <subjectivity.h>
#include <subjects.h>
#include <tactic.h>
#include <terrains.h>
#include <thought.h>
#include <traits.h>
#include <versus.h>

inherit "/std/item";

inherit "/mod/character/combat";

private descriptor array special_attacks;

private descriptor attr_mod;

descriptor add_special_attack(mixed spec) {
	descriptor dxr = Special_Attack(spec);
	special_attacks ||= ({});
	special_attacks += ({ dxr });
	clear_attack_information();
	return dxr;
}

status remove_special_attack(descriptor dxr) {
	descriptor array list = query_special_attacks();
	int index = member(list, dxr);
	if(index == Null)
		return False;
	dxr = 0;
	list = array_splice(list, index);
	if(sizeof(list))
		special_attacks = list;
	else
		special_attacks = 0;
	clear_attack_information();
	return True;
}


void boots_do_equip(mapping args) {
	attr_mod = args["who"]->add_special_attack(([
		Special_Attack_Name			: "Enraged Arc",
		Special_Attack_Vector       : Vector_Arc,
		Special_Attack_Message		: ({ 0, ({ "sidestep", 0 }), "and", ({ "swing", 0 }), "%c", "with incredible speed and might", }),
		Special_Attack_Type         : ({ "cutting", "spirit", "force", }),
		Special_Attack_Skill        : ({ Skill_Axe, Skill_Massive_Blow }),
		Special_Attack_Power        : Special_Attack_Power_Extreme,
		Special_Attack_Activity		: 20,
		Special_Attack_Condition    : Weapon_Required(Weapon_Type_Giant_Axe),
		Special_Attack_Chance       : Special_Attack_Chance_Profuse,
		Special_Attack_Size			: Special_Attack_Size_Huge,
	]));
	attr_mod = args["who"]->add_special_attack(([
		Special_Attack_Name			: "Queen's Cross",
		Special_Attack_Vector       : Vector_Blade,
		Special_Attack_Message		: ({ 0, ({ "swing", 0 }), "%c", "downward at an angle, spinning around and bringing", "%c", "up and across again", }),
		Special_Attack_Type         : ({ "cutting", "spirit", "force", }),
		Special_Attack_Skill        : ({ Skill_Sword, Skill_Massive_Blow }),
		Special_Attack_Power        : Special_Attack_Power_Extreme,
		Special_Attack_Activity		: 20,
		Special_Attack_Condition    : Weapon_Required(Weapon_Type_Giant_Sword),
		Special_Attack_Chance       : Special_Attack_Chance_Profuse,
		Special_Attack_Size			: Special_Attack_Size_Huge,
	]));
	attr_mod = args["who"]->add_special_attack(([
		Special_Attack_Name			: "Massive Hammer Swing",
		Special_Attack_Vector       : Vector_Strike,
		Special_Attack_Message		: ({ 0, ({ "swing", 0 }), "%c", "downward straight at", "%e", "with all", ({ 'r', 0, "might" }), }),
		Special_Attack_Type         : ({ "force", "spirit", "crushing", }),
		Special_Attack_Skill        : ({ Skill_Hammer, Skill_Massive_Blow }),
		Special_Attack_Power        : Special_Attack_Power_Extreme,
		Special_Attack_Activity		: 20,
		Special_Attack_Condition    : Weapon_Required(Weapon_Type_Giant_Hammer),
		Special_Attack_Chance       : Special_Attack_Chance_Profuse,
		Special_Attack_Size			: Special_Attack_Size_Huge,
	]));
	attr_mod = args["who"]->add_special_attack(([
		Special_Attack_Name			: "Massive Flail Swing",
		Special_Attack_Vector       : Vector_Strike,
		Special_Attack_Message		: ({ 0, ({ "swing", 0 }), "%c", "downward straight at", "%e", "with all", ({ 'r', 0, "might" }), }),
		Special_Attack_Type         : ({ "force", "spirit", "crushing", }),
		Special_Attack_Skill        : ({ Skill_Flail, Skill_Massive_Blow }),
		Special_Attack_Power        : Special_Attack_Power_Extreme,
		Special_Attack_Activity		: 20,
		Special_Attack_Condition    : Weapon_Required(Weapon_Type_Giant_Flail),
		Special_Attack_Chance       : Special_Attack_Chance_Profuse,
		Special_Attack_Size			: Special_Attack_Size_Huge,
	]));
	attr_mod = args["who"]->add_special_attack(([
		Special_Attack_Name			: "Reaper's Gambit",
		Special_Attack_Vector       : Vector_Blade,
		Special_Attack_Message		: ({ 0, ({ "jump", 0 }), "back and", ({ "raise", 0 }), "%c", "back momentarily and {{shadowfire}dark energy} rushes into", "%c", ". ", 'c', 0, "then", ({ "leap", 0 }), "forward, swinging", ({ 'r', 0, "%c" }), "with demonic fury", }),
		Special_Attack_Type         : ({ "force", "spirit", "cutting", }),
		Special_Attack_Skill        : ({ Skill_Pole_Arm, Skill_Massive_Blow }),
		Special_Attack_Power        : Special_Attack_Power_Very_Extreme,
		Special_Attack_Activity		: 20,
		Special_Attack_Condition    : Weapon_Required(Weapon_Type_Giant_Scythe),
		Special_Attack_Chance       : Special_Attack_Chance_Profuse,
		Special_Attack_Size			: Special_Attack_Size_Huge,
		Special_Attack_Strike		: Special_Attack_Strike_Supremely_Accurate,
	]));
	attr_mod = args["who"]->add_special_attack(([
		Special_Attack_Name			: "Keen's Lance",
		Special_Attack_Vector       : Vector_Strike,
		Special_Attack_Message		: ({ 0, ({ "gather", 0 }), "{{shadowfire}dark energy} around the", "%c", "and", ({ "thrust", 0 }), "it toward", "%e", }),
		Special_Attack_Type         : ({ "piercing", "spirit", "fire", }),
		Special_Attack_Skill        : ({ Skill_Spear, Skill_Massive_Blow }),
		Special_Attack_Power        : Special_Attack_Power_Very_Extreme,
		Special_Attack_Activity		: 20,
		Special_Attack_Condition    : Weapon_Required(Weapon_Type_Giant_Spear),
		Special_Attack_Chance       : Special_Attack_Chance_Profuse,
		Special_Attack_Size			: Special_Attack_Size_Huge,
		Special_Attack_Strike		: Special_Attack_Strike_Supremely_Accurate,
	]));
	args["who"]->message(({"As",0,({"pull",0}), ({'r', 0, this_object() }),
		"on, they slowly shape themselves to blend with", ({'r', 0, "legs"}),
		"and enhance", ({'r',0,"natural beauty" })}));
}

void boots_do_unequip(mapping args) {
	args["who"]->remove_attribute_modifier(&attr_mod);
}

void configure() {
	::configure();
	armour()->set_race("kielleth");
	add_description(({
	
	"The glossy",
	
		Description(([
                Description_Type                        : Description_Type_Element_Name,
                Description_Index                       : Element(([
                    Element_Type                        : Material_Leather,
                    Element_Color                       : "black",
                ])),
		])),
	
	"thigh boots appear to be comfortable and stylish. ",
	"Covering the feet and legs from toe to thigh, the boots magically adjust to",
	"fit the wearer.  For additional protection,",

		Description(([
                Description_Type                        : Description_Type_Element_Name,
                Description_Index                       : Element(([
                    Element_Type                        : Material_Adamantite,
                    Element_Color                       : "black",
                ])),
		])),
	"plates have been inserted between the lining and the leather.",
	
	}));
	armour()->set_armour_type(Armour_Type_Pair_of_Thigh_Boots);
	armour()->set_armour_style(Armour_Style_Simple);
	set_craft(Craft_Exquisite);
	add_proportion(([
		Element_Type       : Material_Leather,
		Element_Proportion : 0.7,
		Element_Color	   : "black",
	]));
	add_proportion(([
		Element_Type       : Material_Adamantite,
		Element_Proportion : 0.2,
		Element_Part       : Part_Embedment,
		Element_Form       : Form_Plates,
	]));
	add_proportion(([
		Element_Type       : Material_Dweomer,
		Element_Proportion : 0.1,
	]));
	add_property(Prop_Slippery);
	add_hook(Do_Equip_Item, #'boots_do_equip);
	add_hook(Do_Unequip_Item, #'boots_do_unequip);

}
