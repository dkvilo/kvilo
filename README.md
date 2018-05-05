# Variable Manager for Unix-Like
    Author: David Kviloria <datokviloria@gmail.com>
    Version: 0.1

# Build And Install

```
1) $ make init
2) $ make buildx
3) $ make install
4) $ make reset_build
```

# Usage for 1.0

    # Init Config for
    $ kvilo init

    # Set Variable
    $ kvilo set foo=bar

    # Get Variable and print value
    $ kvilo get foo | xargs echo

    # validate variable: Command --validate <key> <value>
    $ kvilo --validate foo bar

    # Print available variables
    $ kvilo list

    # To reset existing config type init command again
    $ kvilo init


# Todo
- add ``unset`` command
- add ``-h`` flag and help menu
- add multiple config support

# Screenshots
![Init Command](https://raw.githubusercontent.com/dkvilo/kfr/master/screenshot/init.png)

![Set Variable](https://raw.githubusercontent.com/dkvilo/kfr/master/screenshot/set.png)

![Get Value](https://raw.githubusercontent.com/dkvilo/kfr/master/screenshot/get.png)

![Valdiate Variable Value](https://raw.githubusercontent.com/dkvilo/kfr/master/screenshot/validate.png)

![List Variables](https://raw.githubusercontent.com/dkvilo/kfr/master/screenshot/list.png)
