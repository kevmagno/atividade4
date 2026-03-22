#include <iostream>
#include <string>

using namespace std;

// ================= CLASSE BASE =================
class AtivoCampo {
private:
    string tag;       // identificador do ativo
    bool bloqueado;   // estado de bloqueio

protected:
    // protected usado apenas para permitir acesso controlado nas derivadas
    bool estaBloqueado() {
        return bloqueado;
    }

public:
    // construtor
    AtivoCampo(string t, bool b) {
        tag = t;
        bloqueado = b;
    }

    string getTag() {
        return tag;
    }

    void exibirBase() {
        cout << "Tag: " << tag
             << " | Bloqueado: " << (bloqueado ? "Sim" : "Nao") << endl;
    }
};


// ================= SENSOR =================
class SensorNivel : public AtivoCampo {
private:
    float nivel;

public:
    // construtor reaproveitando a base
    SensorNivel(string t, bool b, float n) : AtivoCampo(t, b) {
        nivel = n;
    }

    // validação de nivel
    void setNivel(float n) {
        if (!estaBloqueado() && n >= 0) {
            nivel = n;
        } else {
            cout << "Nao foi possivel alterar o nivel\n";
        }
    }

    void exibirResumo() {
        exibirBase();
        cout << "Nivel: " << nivel << endl;
    }

    // função friend para inspeção técnica
    friend void inspecionarSensor(SensorNivel s);
};


// ================= BOMBA =================
class BombaDosadora : public AtivoCampo {
private:
    float vazao;

public:
    // construtor reaproveitando a base
    BombaDosadora(string t, bool b, float v) : AtivoCampo(t, b) {
        vazao = v;
    }

    // validação de vazao
    void setVazao(float v) {
        if (!estaBloqueado() && v >= 0) {
            vazao = v;
        } else {
            cout << "Nao foi possivel alterar a vazao\n";
        }
    }

    void exibirResumo() {
        exibirBase();
        cout << "Vazao: " << vazao << " L/s" << endl;
    }
};


// ================= FRIEND =================
void inspecionarSensor(SensorNivel s) {
    cout << "\n[INSPECAO TECNICA]\n";
    cout << "Nivel atual: " << s.nivel << endl;
}


// ================= MAIN =================
int main() {

    // criando objetos
    SensorNivel s1("SN001", false, 50);
    SensorNivel s2("SN002", true, 80);

    BombaDosadora b1("B001", false, 10);
    BombaDosadora b2("B002", true, 20);

    cout << "\n=== RESUMO ===\n";

    s1.exibirResumo();
    s2.exibirResumo();

    b1.exibirResumo();
    b2.exibirResumo();

    // testando validação
    cout << "\n=== TESTES ===\n";
    s1.setNivel(70);  // deve funcionar
    s2.setNivel(30);  // bloqueado

    b1.setVazao(15);  // deve funcionar
    b2.setVazao(5);   // bloqueado

    // usando friend
    inspecionarSensor(s1);

    return 0;
}