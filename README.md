# ENV Manager

    Version: 0.0.1

# Building locally (Linux and Mac)

```bash
  make build
  make install_mac or install_linux 
```

# Building with Docker
```
  docker build . -t kvilo-1.0.0:beta
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
[ ] Multiple Collection Support [1.0]

# Meta
  **Author**: David Kviloria
  
  **License**: MIT
