-- BlueddoTV -- Create 20/09/18 ---------------------------------------------------------------------------------------------------------------
local t={}
local path = m_simpleTV.Common.GetMainPath(2)
path = path .. '\\luaScr\\user\\blueddotv\\misc\\BlueddoTV.png'  -- Icon for "Additional" menu add-on
t.utf8 = true --  string coding
--t.codepage (0) - code page of non utf8 text
t.name = 'BlueddoTV' -- Name of item in the "Additional" menu if name=='-' then add separator
t.luastring = 'user\\blueddotv\\tvinit.lua' -- lua file name or script
--t.lua_as_scr (false)  - if true then t.luastring is script, overwise t.luastring is file name of lua script
--t.submenu = ('Blueddo Menu') -- string, name of submenu
t.key = string.byte('A') -- 0x01000002 -- letter hotkey (type: byte (ANSI char))
t.ctrlkey = 2  -- modifier keys (type: number) (available value: 0 - not modifier keys, 1 - CTRL, 2 - SHIFT, 3 - CTRL + SHIFT )
t.location = 0 --(0) - 0 - in main menu,1 - in playlist menu, -1 all
t.image= path -- string, image file name

m_simpleTV.Interface.AddExtMenuT(t)

------------------------------------------------------------------------------------------------------------------------------------------------------
if not string.match(package.path,'user\\blueddotv\\blueddotv' , 0)  then
	package.path = package.path .. ';' .. m_simpleTV.MainScriptDir .. 'user\\blueddotv\\tvscr\\?.lua'
end

AddFileToExecute('onconfig',m_simpleTV.MainScriptDir .. "user/blueddotv/tvinitconfig.lua")