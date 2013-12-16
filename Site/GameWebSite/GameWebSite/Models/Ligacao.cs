using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.ComponentModel.DataAnnotations;

namespace GameWebSite.Models
{
    public class Ligacao
    {
        [Key]
        private string LigacaoID { get; set; }
        private string User1ID { get; set; }
        private string User2ID { get; set; }
        private int Força { get; set; }
        private DateTime DataDeInicio { get; set; }
        private string EstadoDaLigacaoID { get; set; }
    }
}