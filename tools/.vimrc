autocmd BufNewFile *.cpp exec ":call SetTitle()"
syntax on
filetype indent plugin on
colorscheme molokai
set encoding=utf-8
set ruler
set showcmd
set number
set tabstop=4
set shiftwidth=4
set hls
set lbr
set t_Co=256
hi MatchParen ctermbg=DarkRed guibg=lightblue

map <C-A> ggVG"+y
map <c-c> "+y
map <c-v> "+p

map <F5> :call Run()<CR>
func! Run()
	exec "w"
	exec "!g++ -Wall % -o %<"  
	exec "!./%<"  
endfunc

func SetTitle()
	let l = 0
	let l = l + 1 | call setline(l,'/* ***************************************************')
	let l = l + 1 | call setline(l,' *	Author        :mutinner                          *')
	let l = l + 1 | call setline(l,' *	Created Time  :'.strftime('%c').'   *')
	let l = l + 1 | call setline(l,' *	File Name     :'.expand('%').'       *')
	let l = l + 1 | call setline(l,' *************************************************** */')
	let l = l + 1 | call setline(l,'')
	let l = l + 1 | call setline(l,'')
endfunc
