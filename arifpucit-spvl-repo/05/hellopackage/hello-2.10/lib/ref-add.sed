/^# Packages using this file: / {
  s/# Packages using this file://
  ta
  :a
  s/ hello / hello /
  tb
  s/ $/ hello /
  :b
  s/^/# Packages using this file:/
}
