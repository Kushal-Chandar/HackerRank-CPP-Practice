#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Spell
{
private:
    string scrollName;

public:
    Spell() : scrollName("") {}
    Spell(string name) : scrollName(name) {}
    virtual ~Spell() {}
    string revealScrollName()
    {
        return scrollName;
    }
};

class Fireball : public Spell
{
private:
    int power;

public:
    Fireball(int power) : power(power) {}
    void revealFirepower()
    {
        cout << "Fireball: " << power << endl;
    }
};

class Frostbite : public Spell
{
private:
    int power;

public:
    Frostbite(int power) : power(power) {}
    void revealFrostpower()
    {
        cout << "Frostbite: " << power << endl;
    }
};

class Thunderstorm : public Spell
{
private:
    int power;

public:
    Thunderstorm(int power) : power(power) {}
    void revealThunderpower()
    {
        cout << "Thunderstorm: " << power << endl;
    }
};

class Waterbolt : public Spell
{
private:
    int power;

public:
    Waterbolt(int power) : power(power) {}
    void revealWaterpower()
    {
        cout << "Waterbolt: " << power << endl;
    }
};

class SpellJournal
{
public:
    static string journal;
    static string read()
    {
        return journal;
    }
};
string SpellJournal::journal = "";

void counterspell(Spell *spell)
{
    if (Fireball *w = dynamic_cast<Fireball *>(spell))
    {
        w->revealFirepower();
    }
    else if (Frostbite *x = dynamic_cast<Frostbite *>(spell))
    {
        x->revealFrostpower();
    }
    else if (Thunderstorm *y = dynamic_cast<Thunderstorm *>(spell))
    {
        y->revealThunderpower();
    }
    else if (Waterbolt *z = dynamic_cast<Waterbolt *>(spell))
    {
        z->revealWaterpower();
    }
    else
    {
        string s1 = spell->revealScrollName();
        string s2 = SpellJournal::read();
        int m = s1.length();
        int n = s2.length();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (s1[i] == s2[j])
                {
                    dp[i + 1][j + 1] = 1 + dp[i][j];
                }
                else
                {
                    dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }
        cout << dp[m][n] << '\n';
    }
}

class Wizard
{
public:
    Spell *cast()
    {
        Spell *spell;
        string s;
        cin >> s;
        int power;
        cin >> power;
        if (s == "fire")
        {
            spell = new Fireball(power);
        }
        else if (s == "frost")
        {
            spell = new Frostbite(power);
        }
        else if (s == "water")
        {
            spell = new Waterbolt(power);
        }
        else if (s == "thunder")
        {
            spell = new Thunderstorm(power);
        }
        else
        {
            spell = new Spell(s);
            cin >> SpellJournal::journal;
        }
        return spell;
    }
};

int main()
{
    int T;
    cin >> T;
    Wizard Arawn;
    while (T--)
    {
        Spell *spell = Arawn.cast();
        counterspell(spell);
    }
    return 0;
}