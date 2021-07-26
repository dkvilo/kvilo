# Kvilo

Current Version: 1.1.3

See [Changelog](https://github.com/dkvilo/kvilo/blob/master/changelog.md)

# Building (Unix)

```bash
  # Install dependencies
  git submodule update --init --recursive

  # Build source
  make build

  # Install binary
  make install_mac or install_linux 
```

# Using Macros

```
$ kvilo init
$ cp conf.lua ~/.kvilo/

$ kvilo my awesome macro
```
Read more about [Custom Macros](https://github.com/dkvilo/kvilo/wiki/Custom-Macros)

# Basic Usage

See detailed information on kvilo's [Wiki Page](https://github.com/dkvilo/kvilo/wiki)

```bash
 Usage: kvilo <action|macro> <?coll> <arg1> <arg2> <flag>

	init        [-i]                    Creates main collection
	init        [-i]  [-f]              Recreates main collection
    init        <col>                   Creates particular collection


	set         [-s]  <key>=<value>     Stores variable in particular collection - default main
	unset       [-u]  <key>             Removes variable from particular collection default main
	get         [-g]  <key>             Gets variable from particular collection - default main
	show|ls                             Lists collection records

	val         [-v]  <key> <value>     Validates variable in collection - default main
	exp-env     [-e-env] > filename     Writes collection to stdout - default main
	exp         [-e]                    Exports .env file - default main
	exp-example [-ee]                   Exports .env-example file (only keys) - default main
	help        [-h]                    Displays help menu

	/usr/bin/kvilo                    David Kviloria <dkvilo>

```

**Author**: David Kviloria


MIT License

Copyright (c) 2021 David Kviloria

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

