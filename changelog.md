
## New Features for 1.0
  - Multiple collections
  - Programable macros using **lua**
  - producing env-example

## Major Changes
  - Set, Get, Val, Show syntax update
  - Renamed default collection from master to main
  - **Note** kvilo init no longer warns you if collection is about to re-initialize, this happens because I want to encourage users to use different collections, you can think main (default) collection as temp storage;


## New syntax
due to adding custom collections old way of usage cli is changed:

For example, if previously you could add value directly into main collection now you can specify custom one:

```bash
kvilo set user name=david
```

in this case ***user*** is a collection name, similar semantic is applied to other actions (set, unset, val, show, ls ...)

Also if you dont specify collection after action key, program will consider that you are preferring to default collection

```bash
kvilo set name=david
```

## Programable macros

In order to use programmable macros, you have to make ***~/.kvilo/conf.lua*** config file.

***conf.lua*** does one exit function called ***boot***

you can think of about ***boot*** as a ***main()*** function for the program.

Boot function can only execute one macro at the time.

also config function has global table called ***kvilo*** which includes global information about main program, which is very useful creating and describing behaviour of macro.

for example ***kvilo*** has fixed amount of cli arguments (why fixed amount?), this also is refereed to software semantic and idea of macros itself, we are making macros to make existing commands shorter and easy to remember. having long macros is against the ida of itself.


## Building simple macro

I'm assuming that you already have defined ***conf.lua*** if not you need to create ***~/.kvilo/conf.lua***


First we need to define macro exit point, in our case ***boot*** function

```lua
boot = function()
  return "echo 'Hello, World'"
end
```

```bash
  kvilo
  # Hello, World
  # Rest of the output ...
```
This is guard less macro, it will be executed every time user calls the kvilo command. but it is not useful, as I have mentioned before we have access to global table ***kvilo*** which includes useful information about runtime, in this case we will need information about cli args that main runtime is receiving.

### Note
We can access fixed amount of cli args in rage 1 and 5

```lua

-- local table of macros
local macros = {}

macros.message = "echo 'Pong'"

boot = function()
  -- here we are checking if kvilo has first argument ping
  -- if so we are returning our macro to be executed
  if kvilo.arg1 == "ping" then
    return macros.message
  end
end
```

to make more useful example lets make ssh macro

this macro will be able to read ssh auth information from the specific collection and connect.


first lets create collection and store server information
```
kvilo set example.com server_info=username@0.0.0.0
```

```lua

-- local table of macros
local macros = {}

macros.message = "echo 'Hello, World'"
macros.ssh = "ssh `kvilo get example.com server_info`"

boot = function()
  -- here we are checking if kvilo has first argument ping
  -- if so we are returning our macro to be executed
  if kvilo.arg1 == "ping" then
    return macros.message
  end

  if kvilo.arg1 == "ssh" and kvilo.arg2 == "myserver" then
    return macros.ssh
  end
end
```

Now if we execute following command we will be able to connect our server, without exposing auth credentials
```bash
kvilo ssh myserver
```

