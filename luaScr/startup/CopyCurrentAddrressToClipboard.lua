-- (13/6/20)
	function CopyCurrentAddrressToClipboard()
		if m_simpleTV.Control.RealAddress
			and m_simpleTV.Control.CurrentAddress ~= ''
		then
			m_simpleTV.Interface.CopyToClipboard(m_simpleTV.Control.CurrentAdress)
			m_simpleTV.OSD.ShowMessageT({text = 'Η τρέχουσα διεύθυνση αντιγράφηκε\n' ..  m_simpleTV.Control.CurrentAdress, color = 0xff00dd00, showTime = 1000 * 5, id = 'channelName'})
-- debug_in_file(m_simpleTV.Control.RealAddress .. '\n')
		end
	end
	local t = {}
	t.utf8 = true
	t.name = 'Αντιγραφή τρέχουσας διεύθυνσης'
	t.luastring = 'CopyCurrentAddrressToClipboard()'
	t.lua_as_scr = true
	t.key = string.byte('V')
	t.ctrlkey = 2
	t.location = 0
	t.image = m_simpleTV.Common.GetMainPath(2) .. 'skin/base/img/osd/infopanel/deint.png'
	m_simpleTV.Interface.AddExtMenuT(t)
	m_simpleTV.Interface.AddExtMenuT({name = '-'})