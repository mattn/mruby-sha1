assert('SHA1 Hash for "ruby"') do
  SHA1.sha1_hex('ruby') == '18e40e1401eef67e1ae69efab09afb71'
end

assert('SHA1 Hash for old example') do
  SHA1::sha1_hex('お前はどこのワカメじゃ') == "de0cd7ded3e47b643b882abf100a7a39"
end
