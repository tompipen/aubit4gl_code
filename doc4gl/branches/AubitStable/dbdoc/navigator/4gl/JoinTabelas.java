/* Esta classe apresenta a ligação entre tabelas num applet
 */

import java.awt.*;
import java.applet.*;

public class JoinTabelas extends Applet 
{
   String MaxLeft;
   String MinLeft;
   String LeftTable;
   String MaxRight;
   String MinRight;
   String RightTable;
   public void init()
   {
      MaxLeft = getParameter("MAXLEFT");
      if (MaxLeft == null)
         MaxLeft = "UM";
      MinLeft = getParameter("MINLEFT");
      if (MinLeft == null)
         MinLeft = "UM";
      LeftTable = getParameter("LEFTTABLE");
      if (LeftTable == null)
         LeftTable = "INDEFENIDA";
      MaxRight = getParameter("MAXRIGHT");
      if (MaxRight == null)
         MaxRight = "VARIOS";
      MinRight = getParameter("MINRIGHT");
      if (MinRight == null)
         MinRight = "ZERO";
      RightTable = getParameter("RIGHTTABLE");
      if (RightTable == null)
         RightTable = "INDEFENIDA";
   }

   public void paint(Graphics g) 
   {
      Dimension r = size();
      g.setColor(Color.red);   
      g.drawRect(20,20,100,100);
      g.drawRect(240,20,100,100);
      g.drawLine(120,70,240,70);

                                             // Desenhar Minimo esquerda
      if (MinLeft.equalsIgnoreCase("UM"))
         g.drawLine(140,60,140,80);
      else if (MinLeft.equalsIgnoreCase("ZERO"))
         g.drawArc(140,65,10,10,0,360);

                                             // Desenhar Maximo esquerda
      if (MaxLeft.equalsIgnoreCase("UM"))
         g.drawLine(130,60,130,80);
      else if (MaxLeft.equalsIgnoreCase("VARIOS"))
      { 
         g.drawLine(130,70,120,60);
         g.drawLine(130,70,120,80);
      }

                                               // Desenhar Minimo direita
      if (MinRight.equalsIgnoreCase("UM"))
         g.drawLine(220,60,220,80);
      else if (MinRight.equalsIgnoreCase("ZERO"))
         g.drawArc(210,65,10,10,0,360);
                                               // Desenhar Maximo direita
      if (MaxRight.equalsIgnoreCase("UM"))
         g.drawLine(230,60,230,80);
      else if (MaxRight.equalsIgnoreCase("VARIOS"))
      {
         g.drawLine(230,70,240,60);
         g.drawLine(230,70,240,80);
      }
     
      /* Nome da tabela 1 */
      /* Tenho de aprender a usar strings */
      g.drawString(LeftTable,40,70);
      /* Nome da tabela 2 */
      g.drawString(RightTable,260,70);
   }
}
