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

map <C-c> ggVG"+y

map <F5> :call Run()<CR>

func! Run()
	exec "w"
	exec "!g++ -std=c++14 -O2 -DNDEBUG -Wall % -o %<"  
	exec "!./%<"  
endfunc

func SetTitle()
	let l = 0
	let l = l + 1 | call setline(l,'/* ***************************************************')
	let l = l + 1 | call setline(l,' *	Author        :mutinner')
	let l = l + 1 | call setline(l,' *	Created Time  :'.strftime('%c'))
	let l = l + 1 | call setline(l,' *	File Name     :'.expand('%'))
	let l = l + 1 | call setline(l,' *************************************************** */')
	let l = l + 1 | call setline(l,'')
	let l = l + 1 | call setline(l,'#include <bits/stdc++.h>')
	let l = l + 1 | call setline(l,'using namespace std;')
	let l = l + 1 | call setline(l,'')
	let l = l + 1 | call setline(l,'')
	exec '10'
endfunc
