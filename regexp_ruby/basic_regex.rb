#!/usr/bin/env ruby
string = "The quick 12 brown foxes jump over the 10 lazy dogs"

p string =~ /quick/

p string =~ /z/ ? "Valid string" : "Invalid"

# Case insensitive
p string =~ /z/i ? "Valid string" : "Invalid"

if string =~ /Z/
    puts "valid"
else
    puts "Invalid"
end