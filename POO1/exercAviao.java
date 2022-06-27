public class Aviao {
	private String fabricante, modelo;
	private int qtdeAssentos;
	
	public void ligar() {
		System.out.println("Ligando o aviao " + fabricante + " " + modelo);
	}
}

public class ExemploAviao {
	public static void main(String[ ] args) {
	// criando uma instância/objeto da classe Aviao
	Aviao aviao1 = new Aviao();
	// atribuindo os valores dos atributos
	aviao1.fabricante = "Boeing";
	aviao1.modelo = "777";
	aviao1.qtdeAssentos = 368;
	// executando os métodos do objeto
	aviao1.ligar();
	}
}