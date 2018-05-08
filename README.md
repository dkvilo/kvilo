# ENV Manager for Project

    Version: 0.0.1

# Build form source (Linux)

```
0) git clone https://github.com/dkvilo/kvilo.git
1) cd kvilo
2) make init
3) make buildx
4) make install
```

# Usage
	Usage: kvilo <command> <arg1> <arg2> <flag>

		init        [-i]                  Initial master
		init        [-i]  [-f]            Force Init   
		set         [-s]  <key>=<value>   Store variable
		unset       [-u]  <key>           Remove variable
		get         [-g]  <key>           Get variable
		show                              See collection
		val         [-v]  <key> <value>   Validate variable
		exp-env     [-e-env] > filename   Write collection to file
		exp         [-e]                  Export .env file
		exp-example [-ee]                 Export .env-example file
		help        [-h]                  Help message

	./usr/bin/kvilo                     David Kviloria <dkvilo>



# Todo
- Multiple Collection Support [1.0]

# Meta

    Author: David Kviloria <datokviloria@gmail.com>
    License: MIT
