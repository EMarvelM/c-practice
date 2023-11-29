#!/usr/bin/env ruby
string = "The quick 12 brown foxes jump over the 10 lazy dogs"

p string =~ /quick/

p string =~ /z/ ? "Valid string" : "Invalid"

if string =~ /z/
    puts "valid"
else
    puts "Invalid"
end