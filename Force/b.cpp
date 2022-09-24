#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;

string getString(char ch[]) {
    string s;
    for (int i = 0; ch[i] != '\0'; i++) s.push_back(ch[i]);
    return s;
}

struct file {
    string name, content;
    int created, edited;
    file() {}
    file(string _name, string _content, int _created) {
        name = _name;
        content = _content;
        created = _created;
        edited = _created;
    }
    file(string _name, string _content, int _created, int _edited) {
        name = _name;
        content = _content;
        created = _created;
        edited = _edited;
    }
};

struct Branch {
    string name;
    deque<Branch*> child;
    deque<file*> files;
    map<string, file*> mf;
    Branch() {}
    Branch(string _name) {name = _name;}

    void removeOldestFile() {
        file* f = files.front();
        files.pop_front();
        mf.erase(f->name);
    }

    void addFile(file* f) {
        if (files.size() == 50) removeOldestFile();
        mf[f->name] = f;
        files.push_back(f);
    }

    void editFile(string fname, string data, int t) {
        if (mf.find(fname) != mf.end()) {   
            mf[fname]->content = data;
            mf[fname]->edited = t;
        }
    }
};

Branch* root;
map<string, Branch*> mp;

void init() {
    root = new Branch("root");
    for (auto i: mp) {
        for (file* j: i.second->files) delete j;
        delete i.second;
    }
    mp.clear();
    mp["root"] = root;
}

void create(int t, char mb[], char mf[], char md[]) {
    string bn = getString(mb), fn = getString(mf), con = getString(md);
    file* f = new file(fn, con, t);
    Branch* b = mp[bn];
    b->addFile(f);
}

void edit(int t, char mb[], char mf[], char md[]) {
    string bn = getString(mb), fn = getString(mf), con = getString(md);
    Branch* b = mp[bn];
    b->editFile(fn, con, t);
}

void branch(int t, char mb[], char mc[]) {
    string bn = getString(mb), cn = getString(mc);
    Branch* pb = mp[bn];
    Branch* cb = new Branch(cn);
    mp[cn] = cb;
    for (auto i: pb->files) {
        cb->files.push_back(new file(i->name, i->content, i->created, i->edited));
    }
    pb->child.push_back(cb);
}

void dfs(Branch* u) {
    if (u->child.empty()) return;
    for (Branch* v: u->child) {
        dfs(v);
        for (auto i: v->files) {
            if (u->mf.find(i->name) == u->mf.end()) 
                u->addFile(new file(i->name, i->content, i->created, i->edited));
            else {
                file* ff = u->mf[i->name];
                if (ff->created == i->created && i->edited > ff->edited) {
                    ff->content = i->content;
                    ff->edited = i->edited;
                }
            }
            v->mf.erase(i->name);
            delete i;
        }
        mp.erase(v->name);
        delete v;
    }
    u->child.clear();
}

void merge(int t, char mb[]) {
    string bn = getString(mb);
    Branch* b = mp[bn];
    dfs(b);
}

int readFile(int t, char mb[], char mf[], char retString[]) {
    string bn = getString(mb), fn = getString(mf);
    Branch* b = mp[bn];
    string res = b->mf[fn]->content;
    for (int i = 0; i < res.size(); i++) retString[i] = res[i];
    retString[res.size()] = '\0';
    return res.size();
}

int main() {
    
}