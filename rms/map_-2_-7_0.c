#include <Sinbyen.h>
#include <room.h>
#include <item.h>

inherit Sinbyen_Room("Map_Base");

#define client           this_player()
#define owner_file       Sinbyen_NPC("sneva")
#define wealth_query     client->query_wealth()
#define savings_added(x) client->add_wealth(x)
#define initial_deposit  5000
#define Percent_Charge   20
#define owner            find_object(owner_file)

void configure() {
	Map_Base::configure();
	set_short("The Sinbyen Bank");
	set_exit_flags(Direction_Northwest, Exit_Flag_Inobvious | Exit_Flag_Requires_Intangibility);
	set_exit_flags(Direction_Northeast, Exit_Flag_Inobvious | Exit_Flag_Requires_Intangibility);
	set_exit_flags(Direction_Southwest, Exit_Flag_Inobvious | Exit_Flag_Requires_Intangibility);
	add_exit(Direction_West);
	add_exit(Direction_North);
	add_exit(Direction_East);
	set_contents(({
		Sinbyen_NPC("sneva"),
	}));
	add_description(([
		Description_Type                                : Description_Type_Simple,
		Description_Content                             : ({
			"this is a small bank",
		}),
		Description_Order                               : Description_Order_Early,
	]));
	add_abstract_item(([
		Abstract_Item_Identity                          : ([
			Identity_Nouns           			        : ({ "desk" }),
		]),
		Abstract_Item_Attach_Description                : ([
			Description_Type                            : Description_Type_Simple,
			Description_Content                         : ({
				({ 'a', 0 }), "sits in the center of the room"
			}),
			Description_Order                           : Description_Order_Early,
		]),
		Abstract_Item_Elements                          : ({
			([
				Element_Type                            : Material_Pine,
                Element_Color                           : "black",
			]),
		}),
        Abstract_Item_Descriptions                      : ({
            ([
                Description_Type                        : Description_Type_Simple,
                Description_Content                     : ({
                    ({ 't', 0 }), "is clean and polished.",
                }),
            ]),
        }),
	]));
	add_abstract_item(([
		Abstract_Item_Identity                          : ([
			Identity_Nouns		                        : ({ "shelves" }),
		]),
		Abstract_Item_Attach_Description                : ([
			Description_Type                            : Description_Type_Simple,
			Description_Content                         : ({
				({ 'n', 0 }), "line the walls"
			}),
			Description_Order                           : Description_Order_Early,
		]),
		Abstract_Item_Elements                          : ({
			([
				Element_Type                            : Material_Pine,
                Element_Color                           : "black",
			]),
		}),
        Abstract_Item_Descriptions                      : ({
            ([
                Description_Type                        : Description_Type_Simple,
                Description_Content                     : ({
                    ({ 't', 0 }), "are laden with files and records.",
                }),
            ]),
        }),
	]));
	add_door("east", Sinbyen_Misc("vault_exterior"));
}

string pile_description(int amount) {
	object coin = clone_object(LS_Misc("money"));
	coin->set_value(amount);
	string out = coin->query_short();
	coin->remove();
	return out;
}

int query_max_savings_balance(object clientele) {
	int total_value = clientele->query_effective_skill(Skill_Finance, True) + clientele->query_effective_skill(Skill_Ownership, True);
	object array primary_skills = Skill_Class(Skill_Class_Social)->query_skill_class_contents();
	object array secondary_skills = Skill_Class(Skill_Class_Trade)->query_skill_class_contents() +
		Skill_Class(Skill_Class_Craft)->query_skill_class_contents();
	foreach( object sk : primary_skills) {
		if(Is_Skill(sk))
			total_value += clientele->query_skill(sk->query_skill_code()) / 2;
	}
	foreach( object sk : secondary_skills) {
		if(Is_Skill(sk))
			total_value += clientele->query_skill(sk->query_skill_code()) / 4;
	}
	total_value -= clientele->query_skill(Skill_Carousing);
	total_value -= clientele->query_skill(Skill_Gambling);
	total_value *= 300;
	total_value += clientele->query_quest_points() * 1000;
	return max(total_value, 10);
}

void add_savings(object who, int amount);
int query_savings(object who);

int reduced(int i) {
	return (i * (100 - Percent_Charge)) / 100;
}

status open_account() {
	object who = client;
	if(!owner)
		return notify_fail("And who are you going to get to do this for you?");
	if(who->query_ghost()) {
		owner->init_command("say Sorry, " + who->query_name(owner) + ", I don't do business with the spirit realm.");
		return True;
	}
	who->message(({ 0, ({ "ask", 0 }), "to open an account" }));
	if(query_savings(who)) {
		owner->init_command("say Umm.. " + who->query_name(owner) + ", you've already got an account with me.");
		return True;
	}
	if(wealth_query < initial_deposit) {
		owner->init_command("say You don't have the initial deposit, " + who->query_name(owner) + "!");
		return True;
	}
	savings_added(-initial_deposit);
	who->display(({
		owner, ({ "take", owner }), ({ 's', 0, "initial deposit," }), ({ 'a', pile_description(initial_deposit) }), ", and", ({ "heap", owner }),
		"it on the counter;", ({ 'p', owner }), ({ "wave", owner }), ({ 'r', owner, "hands" }),
		"over it, and it disappears",
	}));
	owner->message(({
		0, ({ "open", 0 }), "an account for", who,
	}), ({ who }));
	owner->init_command("say Thank you very much. Your business is appreciated.");
	add_savings(who, reduced(initial_deposit));
	return True;
}

status close_account() {
	if(!owner)
	  return notify_fail("And who are you going to get to do this for you?\n");
		if(client->query_ghost()) {
		  owner->init_command("say Sorry " + client->query_name(owner) +
			", I don't do business with the spirit realm");
		  return 0;
		}
		client->message(({ 0, ({ "ask", 0 }), "to close", ({ 'r', 0, "account" })}));
	if(!query_savings(client)) {
	  owner->init_command("say How can you close an account you don't have?");
	  return True;
	}
	owner->message(({ 0, ({ "look", 0 }), "dismayed, but hands over", ({ 'a', pile_description(query_savings(client)) }), ", although", ({ 'p', 0 }), ({ "seem", 0 }), "very sad to part with it" }));
	savings_added(query_savings(client));
	client->remove_info("SAVINGS");
	return True;
}

status account_deposit(int amt) {
	int sav;
	unless(owner)
		return notify_fail("And who are you going to get to do this for you?\n");
	if(client->query_ghost()) {
		owner->init_command("say Sorry " + client->query_name(owner) +
			", I don't do business with the spirit realm");
		return False;
	}
	client->message(({ 0, ({ "ask", 0 }), "to make a deposit" }));
	sav = query_savings(client);
	unless(sav) {
		owner->init_command("say You don't have an account, " + client->query_name(owner) + "!");
		return True;
	}
	if(amt <= 0) {
		owner->init_command("say You can't deposit negative money, "+client->query_name(owner)+"!");
		return True;
	}
	if(amt == 1) {
	    owner->init_command("say Minimum deposit is two gold coins, " +client->query_name(owner) + ".");
	    amt = 2;
	}
	int max_balance = query_max_savings_balance(client);
	if(max_balance - sav <= 2 || sav + reduced(amt) > max_balance) {
	        owner->init_command("say That would put you over your balance limit.");
			return True;
	}
	if(amt > wealth_query) {
	  owner->init_command("say That's more gold than you have!");
	  return True;
	}
	if(amt < 0) {
	  owner->init_command("say That's impossible, " + client->query_name(owner) + ".");
	  return True;
	}
	owner->message(({ 0, ({ "take", 0 }), ({ 's', client, pile_description(amt) }), "and", ({ "wave", 0 }), ({ 'r', 0, "hands" }), "over it making it vanish into thin-air" }));
	owner->init_command("say You now have " + numerical(reduced(amt) + sav) + " gold available to your account.");

	savings_added(-amt);
	add_savings(client, reduced(amt));
	return True;
}

status account_withdraw(int amt) {
	int sav;
	if(!owner)
	  return notify_fail("And who are you going to get to do this for you?\n");
  if(client->query_ghost()) {
	owner->init_command("say Sorry " + client->query_name(owner) +
	 ", I don't do business with the spirit realm");
	return 0;
  }
	   client->message(({ 0, ({ "ask", 0 }), "to make a withdrawal" }));
	sav = query_savings(client);
	if(!sav) {
	  owner->init_command("say Maybe you should open an account first.");
	  return True;
	}
	if(amt > sav) {
		amt = sav;
	}
	if(amt < 0) {
	  owner->init_command("say That's impossible, I'm not a fool.");
	  return True;
	}
	owner->init_command("emit retrieve something from beneath the desk");
	owner->init_command("say You now have " + numerical(sav - amt) + " gold left in your account.");
	owner->message(({ 0, ({ "nod", 0 }), "and", ({ "hand", 0 }), "over", ({ 'a', pile_description(amt) })}));
	savings_added(amt);
	add_savings(client, -amt);
	if(amt == sav) {
	  owner->init_command("say That was the last of your savings; your account is now closed.");
	  client->remove_info("SAVINGS");
	}
	return True;
}

int query_savings(object who) {
mixed amt;
	amt = who->query_info("SAVINGS");
	if(stringp(amt))
	  amt = to_int(amt);
	return amt;
}

void add_savings(object who, int amt) {
	who->set_info("SAVINGS", query_savings(who) + amt);
}

status account_balance() {
	int amt;
	status backpay = False;
	string extras = "";
	if(!owner)
    return notify_fail(({
       "There is noone here to assist", 0
    }));
	amt = query_savings(client);
	if((query_max_savings_balance(client) - amt) < 0) {
		backpay = True;
		extras = "cannot deposit anymore as you are already overbalanced by " + numerical(abs(query_max_savings_balance(client) - amt)) + " gold.";
	} else {
		extras = "can deposit " + numerical(query_max_savings_balance(client) - amt) + " more gold into your account.";
	}
	client->message(({ 0, ({ "ask", 0 }), "for a balance report" }));
	if(!amt) {
	  owner->init_command("say You don't have an account, " + client->query_name(owner) + "!");
	 return True;
	}
	owner->init_command("say Thank you " + client->query_name(owner) + ", you currently have a balance of " + numerical(amt) + " gold, and " +
		extras);
	return True;
}

void init() {
::init();
	add_action("account_usage", "account");
}
status account_usage( string info ) {
	string request;
	int amount;
	unless(info)
		return notify_fail( ({ 0, "can perform the following transactions here. ", "{{white}account [}{{white}open | close | deposit [{{gray}amount}] | withdraw [{{gray}amount}] | balance]}" }) );
	if(sscanf(info, "%s %d", request, amount) == 2 ) {
		switch(request) {
			case "deposit" :
				return account_deposit(amount);
				break;
			case "withdraw" :
				return account_withdraw(amount);
				break;
			default : return False;
		}
	} else if(sscanf(info, "%s", request) == 1) {
		switch(request) {
			case "open" :
				return open_account();
				break;
			case "close" :
				return close_account();
				break;
			case "balance" :
				return account_balance();
			default : return False;
		}
	}
	return True;
}

void reset() {
object obj;
::reset();
	if(obj = owner_file->load(1))
	  obj->move(this_object());
}