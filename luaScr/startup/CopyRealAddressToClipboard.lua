-- (13/6/20)
	function CopyRealAddressToClipboard()
		if m_simpleTV.Control.RealAddress
			and m_simpleTV.Control.RealAddress ~= ''
		then
			m_simpleTV.Interface.CopyToClipboard(m_simpleTV.Control.RealAddress)
			m_simpleTV.OSD.ShowMessageT({text = 'Η πραγματική διεύθυνση αντιγράφηκε', color = 0xff00dd00, showTime = 1000 * 5, id = 'channelName'})
-- debug_in_file(m_simpleTV.Control.RealAddress .. '\n')
		end
	end
	local t = {}
	t.utf8 = true
	t.name = 'Αντιγραφή πραγματικής διεύθυνσης'
	t.luastring = 'CopyRealAddressToClipboard()'
	t.lua_as_scr = true
	t.key = string.byte('C')
	t.ctrlkey = 2
	t.location = 0
	t.image = m_simpleTV.Common.GetMainPath(2) .. 'skin/base/img/osd/infopanel/deint.png'
	m_simpleTV.Interface.AddExtMenuT(t)
	m_simpleTV.Interface.AddExtMenuT({name = '-'})