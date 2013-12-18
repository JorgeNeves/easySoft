using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.ComponentModel.DataAnnotations;

namespace MvcApplication1.Models
{
    public class Ligacao
    {

        public int LigacaoID { get; set; }
        public int User1ID { get; set; }
        public int User2ID { get; set; }
        public int Força { get; set; }
        public DateTime DataDeInicio { get; set; }
        public int EstadoDaLigacaoID { get; set; }
    }
}