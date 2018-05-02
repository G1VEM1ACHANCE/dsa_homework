set nocompatible
filetype off

set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
Plugin 'VundleVim/Vundle.vim'
Plugin 'scrooloose/nerdtree'
Plugin 'geoffharcourt/vim-matchit'
Plugin 'Xuyuanp/nerdtree-git-plugin'
Plugin 'AutoComplPop'
call vundle#end()
filetype plugin indent on

set t_Co=256
set cursorline
set number
set mouse=a
set expandtab
set tabstop=4
set shiftwidth=4
set incsearch
set hlsearch
set autowrite
autocmd Filetype html setlocal ts=2 sw=2

colorscheme pixelmuerto
syntax on

nmap gh <C-w>h
nmap gj <C-w>j
nmap gk <C-w>k
nmap gl <C-w>l
nmap fk <C-e>
nmap fj <C-y> 

map <C-n> :NERDTreeToggle<CR>
map <F2> a<C-R>=strftime("%c")<CR><Esc>
map <F12> <Esc>:w<Return>   
