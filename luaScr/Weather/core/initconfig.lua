
local t ={}
t.name = 'Weather'
t.htmlUri = Weather.FullDir_UTF8..'/Dialog/WeatherDialog.html'
t.luaUri  = 'user/'..Weather.NameDir..'/Dialog/WeatherDialog.lua'
t.iconUri  = Weather.FullDir_UTF8 .. '/Dialog/img/logo.png'
m_simpleTV.Config.AddExtDialogT(t)
