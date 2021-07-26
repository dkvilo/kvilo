## Changelog for 1.1.3
  - Added Lua 5.2.0 as a git submodule

## New Features for 1.1.2

  - Multiple collections
  - Programable macros using **lua**
  - Producing env-example

## Major Changes
  - **Set**, **Get**, **Val**, Show syntax update
  - Renamed default collection from master to main
  - **Note** kvilo init no longer warns you if the collection is about to re-initialize, this happens because I want to encourage users to use different collections, you can think of the main (default) collection as temp storage;

## New syntax
due to adding custom collections old way of usage CLI is changed:

For example, if previously you could add value directly into the main collection now you can specify a custom one:

```bash
kvilo set user name=david
```

in this case ***user*** is a collection name, a similar semantic is applied to other actions (set, unset, val, show, ls ...)

Also if you don't specify the collection after-action key, the program will consider that you are preferring to the default collection

```bash
kvilo set name=david
```
