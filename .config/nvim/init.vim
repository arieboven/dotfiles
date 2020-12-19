let mapleader = ' '

" If plugged is not installed, install it
if ! filereadable(system('echo -n "${XDG_CONFIG_HOME:-$HOME/.config}/nvim/autoload/plug.vim"'))
    echo "Downloading junegunn/vim-plug to manage plugins..."
    silent !mkdir -p ${XDG_CONFIG_HOME:-$HOME/.config}/nvim/autoload/
    silent !curl "https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim" > ${XDG_CONFIG_HOME:-$HOME/.config}/nvim/autoload/plug.vim
    autocmd VimEnter * PlugInstall
endif

set nocompatible

call plug#begin(system('echo -n "${XDG_CONFIG_HOME:-$HOME/.config}/nvim/plugged"'))
Plug 'valloric/YouCompleteMe'
Plug 'ap/vim-css-color'
Plug 'preservim/nerdtree'
Plug 'alvan/vim-closetag'
Plug 'tpope/vim-surround'
Plug 'tpope/vim-commentary'
call plug#end()
" Run :PlugInstall to install plugins

let g:ycm_show_diagnostics_ui = 0       " Disable error checking
let g:closetag_filetypes = 'html,xml'   " Enable closetag on these filetypes

" Spelling check
map <F8> :setlocal spell! spelllang=en_us<CR>

filetype plugin indent on
set title
set laststatus=2
set number relativenumber   " Set line number
syntax enable               " Enable syntax
set encoding=utf-8
set t_Co=256                " Enable 256 colors
set background=light
set undodir=/tmp
set undofile
set nobackup

set ignorecase              " Ignore case while searching
set smartcase
set incsearch
set hlsearch
set wildmode=longest,list,full

set tabstop=4               " Number of visual spaces per TAB
set softtabstop=4           " Number of speces in tab when editing
set shiftwidth=4            " Indents will have a witdth of 4
set expandtab               " Tabs are spaces
set smartindent

set splitbelow splitright   " When use split new window below, or right

" Toggle NERDTree
nnoremap <leader>n :NERDTreeToggle<CR>
" Replace all words
nnoremap <leader>r :%s/\<<C-r><C-w>\>//g<Left><Left>
" Find word under cursor
nnoremap <leader>f *``
" clear highlighting search
nnoremap <silent> <leader>c :nohlsearch<CR>
" Insert empty line
nnoremap <silent> <leader>o o<Esc>
nnoremap <silent> <leader>O O<Esc>

" Check file in shellcheck:
nnoremap <leader>s :!clear && shellcheck -x %<CR>

" restore cursor position when reopening a file, except if it's a git commit
autocmd BufReadPost * if @% !~# '\.git[\/\\]COMMIT_EDITMSG$' && line("'\"") > 1 && line("'\"") <= line("$") | exe "normal! g`\"" | endif

" Save file as sudo on files that require root permission
cnoremap w!! execute 'silent! write !sudo tee % >/dev/null' <bar> edit!

au BufRead,BufNewFile *.note setf note

" Run xrdb whenever Xdefaults or Xresources are updated.
autocmd BufWritePost *Xresources,*Xdefaults !xrdb %

vnoremap <silent> <C-c> "*y :let @+=@*<CR>
map <C-p> "+p
map <silent> <C-g> :YcmCompleter GoTo<CR>

" autocmd BufNewFile *.py 0r ~/.vim/templates/python
autocmd BufNewFile *.py exec "normal! i# @author: Arie Boven\n\ndef main():\npass\n\nif __name__ == \"__main__\":\nmain()\<Esc>3kciw"
autocmd BufNewFile *.c exec "normal! i/* @author Arie Boven */\n\n#include <stdio.h>\n\nint main() {\n\nreturn 0;\n}\<Esc>2k"

" Statusline
let g:currentmode={
       \ 'n'  : 'NORMAL',
       \ 'v'  : 'VISUAL',
       \ 'V'  : 'V·Line',
       \ "\<C-v>" : 'V·Block',  
       \ 'i'  : 'INSERT',
       \ 'R'  : 'R',
       \ 'Rv' : 'V·Replace',
       \ 'c'  : 'Command',
       \}

function! ReadOnly()
    if &readonly || !&modifiable
        return ' [READ ONLY] '
    else
        return ''
endfunction

set statusline=
set statusline+=%3*\ %{toupper(g:currentmode[mode()])}
set statusline+=\ %1*\ %F\ %2*
set statusline+=\ %{&modified?'[+]':''}
set statusline+=\ %4*%{ReadOnly()}%2*
set statusline+=%=
set statusline+=%2*%y
set statusline+=\ %{&fileencoding?&fileencoding:&encoding}
set statusline+=\ \|\ \[%{&fileformat}\]
set statusline+=\ \|\ %p%%
set statusline+=\ \|\ %l:%c\ %*

" Colors
hi User1 ctermfg=253 ctermbg=236
hi User2 ctermfg=246 ctermbg=236
hi User3 ctermfg=007 ctermbg=052
hi User4 ctermfg=250 ctermbg=017
hi Visual ctermbg=240
