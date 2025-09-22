# mruby-sha1

A simple SHA1 implementation for mruby.

## Usage

```ruby
require 'sha1'
digest = SHA1.digest("hello world")
puts digest.unpack1('H*') # prints "2aae6c35c94fcfb415dbe95f408b9ce91ee846ed"
```

## Requirements

- mruby

## Installation

Add `mruby-sha1` to your `build_config.rb`:

```ruby
MRuby::Build.new do |conf|
  conf.gem :github => 'mattn/mruby-sha1'
end
```

Then run `rake` to build your mruby with the SHA1 gem included.

## License

This project is licensed under a dual-licensing model:

- **sha.c**: Licensed under the GNU General Public License (GPL). See the file `sha.c` for details.
- **All other files**: Licensed under the MIT License.

## Author

Yasuhiro Matsumoto (a.k.a. mattn)

